#!/usr/bin/env python3
"""Extract and repack kernel extensions from a decompressed Apple Silicon BootKC fileset.

In a BootKC fileset, each kext's segments are NOT laid out contiguously: only
__TEXT sits at the LC_FILESET_ENTRY fileoff; __TEXT_EXEC, __DATA, __DATA_CONST,
__LINKEDIT are placed elsewhere in the kernelcache, sometimes page-shared with
other kexts.

This script repacks each module: every segment's bytes are appended to a new
file in load-command order and LC_SEGMENT_64 fileoff plus section offset are
rewritten. Virtual addresses are preserved verbatim, so addresses in
disassembly remain directly comparable to the running kernel.

Offset policy: every rebased offset is validated against the size of the output
file. Nothing is wrapped or masked. If a rebased offset is negative or outside
the file, the offending field is zeroed and the condition is reported on stderr
as a LIMITATION line, so a malformed field can never masquerade as a valid one.

Known limitations (by design, not bugs to chase):
  - __LINKEDIT is page-shared in a BootKC. Repacking copies each kext's own
    __LINKEDIT range, so cross-kext shared bytes appear more than once. Symbol
    tables therefore survive but are not deduplicated.
  - LC_DYSYMTAB symbol *indices* (ilocalsym/nlocalsym/iextdefsym/...) refer to
    the kernelcache-wide symbol table, not to this module's LC_SYMTAB. They are
    left untouched, so `strings(1)`/otool may reject the file. Use rz-bin,
    rizin, or a raw grep for strings; symbols via LC_SYMTAB remain correct.
  - Code signing is invalidated. These files are for static analysis only and
    must not be loaded.

Read-only w.r.t. the input.
"""
import struct
import sys
import os

LC_SEGMENT_64 = 0x19
LC_FILESET_ENTRY = 0x80000035
LC_SYMTAB = 0x2
LC_DYSYMTAB = 0xB
LC_FUNCTION_STARTS = 0x26
LC_DATA_IN_CODE = 0x29
LC_DYLD_INFO_ONLY = 0x80000022

LIMITATIONS = []


def note(msg):
    LIMITATIONS.append(msg)
    print(f"LIMITATION: {msg}", file=sys.stderr)


def commands(hdr):
    ncmds = struct.unpack_from("<I", hdr, 16)[0]
    off = 32
    out = []
    for _ in range(ncmds):
        cmd, cs = struct.unpack_from("<2I", hdr, off)
        out.append((cmd, cs, off))
        off += cs
        if cs == 0:
            break
    return out


def fileset_entries(hdr):
    out = []
    for cmd, cs, off in commands(hdr):
        if cmd == LC_FILESET_ENTRY:
            vmaddr, fileoff, entry_id, _res = struct.unpack_from("<QQII", hdr, off + 8)
            name = hdr[off + entry_id:off + cs].split(b"\0")[0].decode("utf-8", "replace")
            out.append({"name": name, "fileoff": fileoff, "vmaddr": vmaddr})
    return out


def valid(off, size):
    return 0 <= off <= size


def repack(data, entry, outpath):
    base = entry["fileoff"]
    hdr_len = struct.unpack_from("<I", data, base + 20)[0] + 32
    hdr = bytearray(data[base:base + hdr_len])
    lcs = commands(hdr)

    # Pass 1: lay out segments, build the body, record each segment's delta.
    body = bytearray()
    seg_delta = {}
    drops = []
    for cmd, cs, off in lcs:
        if cmd != LC_SEGMENT_64:
            continue
        segname = hdr[off + 8:off + 24].split(b"\0")[0].decode()
        fo, fsz = struct.unpack_from("<QQ", hdr, off + 40)
        if fsz == 0:
            continue
        src = data[fo:fo + fsz]
        if len(src) != fsz:
            note(f"{entry['name']} {segname}: short read {len(src)}/{fsz} bytes")
            continue
        new_fo = hdr_len + len(body)
        if not valid(new_fo, hdr_len + len(body) + fsz):
            note(f"{entry['name']} {segname}: rebased fileoff {new_fo} out of range")
            drops.append((off, cs))
            continue
        body += src
        seg_delta[segname] = new_fo - fo
        struct.pack_into("<Q", hdr, off + 40, new_fo)
        nsects = struct.unpack_from("<I", hdr, off + 64)[0]
        soff = off + 72
        for _ in range(nsects):
            sec_off = struct.unpack_from("<I", hdr, soff + 48)[0]
            if sec_off:
                rebased = new_fo + (sec_off - fo)
                ssize = struct.unpack_from("<Q", hdr, soff + 40)[0]
                if valid(rebased, hdr_len + len(body)) and valid(rebased + ssize, hdr_len + len(body)):
                    struct.pack_into("<I", hdr, soff + 48, rebased)
                else:
                    note(f"{entry['name']} {segname}: section offset {rebased}+{ssize} out of range; zeroed")
                    struct.pack_into("<I", hdr, soff + 48, 0)
                    struct.pack_into("<Q", hdr, soff + 40, 0)
            soff += 80

    total = hdr_len + len(body)

    # Pass 2: rebase __LINKEDIT-relative metadata, validating each result.
    delta = seg_delta.get("__LINKEDIT")
    if delta is not None:
        for cmd, cs, off in lcs:
            if cmd == LC_SYMTAB:
                symoff, nsyms, stroff, strsize = struct.unpack_from("<IIII", hdr, off + 8)
                s, t = symoff + delta, stroff + delta
                if valid(s, total) and valid(s + nsyms * 16, total) and valid(t, total) and valid(t + strsize, total):
                    struct.pack_into("<IIII", hdr, off + 8, s, nsyms, t, strsize)
                else:
                    note(f"{entry['name']} LC_SYMTAB out of range after rebase; zeroed")
                    struct.pack_into("<IIII", hdr, off + 8, 0, 0, 0, 0)
            elif cmd == LC_DYSYMTAB:
                # offsets (not indices) are file positions into __LINKEDIT
                f = list(struct.unpack_from("<18I", hdr, off + 8))
                ok = True
                for i in (0, 2, 4, 6, 8, 10, 12):
                    if f[i]:
                        r = f[i] + delta
                        if not valid(r, total):
                            ok = False
                            break
                        f[i] = r
                if ok:
                    struct.pack_into("<18I", hdr, off + 8, *f)
                else:
                    note(f"{entry['name']} LC_DYSYMTAB offset out of range after rebase; zeroed")
                    struct.pack_into("<18I", hdr, off + 8, *([0] * 18))
            elif cmd in (LC_FUNCTION_STARTS, LC_DATA_IN_CODE):
                doff, dsz = struct.unpack_from("<II", hdr, off + 8)
                if doff:
                    r = doff + delta
                    if valid(r, total) and valid(r + dsz, total):
                        struct.pack_into("<I", hdr, off + 8, r)
                    else:
                        note(f"{entry['name']} cmd 0x{cmd:x} dataoff out of range; zeroed")
                        struct.pack_into("<II", hdr, off + 8, 0, 0)
            elif cmd == LC_DYLD_INFO_ONLY:
                vals = list(struct.unpack_from("<10I", hdr, off + 8))
                ok = True
                for i in (0, 2, 4, 6, 8):
                    if vals[i]:
                        sz = vals[i + 1]
                        r = vals[i] + delta
                        if not (valid(r, total) and valid(r + sz, total)):
                            ok = False
                            break
                        vals[i] = r
                if ok:
                    struct.pack_into("<10I", hdr, off + 8, *vals)
                else:
                    note(f"{entry['name']} LC_DYLD_INFO_ONLY out of range; zeroed")
                    struct.pack_into("<10I", hdr, off + 8, *([0] * 10))

    for off, cs in drops:
        struct.pack_into("<I", hdr, off, 0)

    with open(outpath, "wb") as f:
        f.write(hdr)
        f.write(body)
    return total


def main():
    src, outdir = sys.argv[1], sys.argv[2]
    want = sys.argv[3].lower() if len(sys.argv) > 3 else None
    data = open(src, "rb").read()
    if struct.unpack_from("<I", data, 0)[0] != 0xFEEDFACF:
        raise SystemExit("not a 64-bit Mach-O fileset")
    hdr_len = struct.unpack_from("<I", data, 20)[0] + 32
    ents = fileset_entries(data[:hdr_len])
    os.makedirs(outdir, exist_ok=True)
    print(f"fileset entries={len(ents)}", file=sys.stderr)
    n = 0
    for e in ents:
        if want and want not in e["name"].lower():
            continue
        safe = (e["name"] or "unnamed").replace("/", "_")
        p = os.path.join(outdir, safe + ".macho")
        size = repack(data, e, p)
        if not want:
            continue
        print(f"{e['name']}\tvmaddr=0x{e['vmaddr']:x}\trepacked={size}")
        n += 1
    if want:
        print(f"wrote {n} module(s) to {outdir}")


if __name__ == "__main__":
    main()
