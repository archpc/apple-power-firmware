#!/usr/bin/env python3
"""Pass 4 -- window detail for the 12 selected pairs + decoded constant cross-check.

Selection (documented in semantics.md):
  * every pair whose canonical mnemonic sequence is NOT equal (5 pairs:
    0x1178, 0x1df0, 0xa018, 0xbb4c, 0xcf38);
  * the 7 pairs with the most non-target operand changes
    (0x17cc, 0x8ff4, 0x1244, 0x9ddc, 0xc78c, 0xd908, 0x9964).
That is 12 of 155; DIFF.md has no "section 2e size-changed" list (its section 2
is prose only), and only ONE of the 155 pairs changes body size at all
(0x1df0, +8 B), so a top-10 size-changed list does not exist to reconcile.

Prints, for each selected pair, the decoded instruction windows in both images,
and writes windows12.json. Also emits the decoded-immediate multiset comparison
over all 155 pairs (non-pointer constants only).
"""
import json, os, re, subprocess, collections

REPO = "/Users/sein/.hermes/artifacts/apple-power-firmware"
DELEG = os.path.join(REPO, "evidence/magsafe-cortexm/delegated")
OUT = os.path.join(DELEG, "semantics")
IMG = {"3112": os.path.join(REPO, "firmware/images/A2363_3.1.12_10M1543_base0.bin"),
       "320": os.path.join(REPO, "firmware/images/A2363_3.2.0_10M13722_base0.bin")}
LEN = {k: os.path.getsize(v) for k, v in IMG.items()}
RIZIN = ["rizin", "-e", "scr.color=0", "-a", "arm", "-b", "16", "-q"]
BRANCH = re.compile(r"^(b|bl|bx|blx|b[a-z]{1,2}|cbz|cbnz)$")
MEM = re.compile(r"\[[^\]]*\]")
HEX = re.compile(r"(?<![0-9a-z])0x[0-9a-f]+")

SEL = ["0x1178", "0x1df0", "0xa018", "0xbb4c", "0xcf38",
       "0x17cc", "0x8ff4", "0x1244", "0x9ddc", "0xc78c", "0xd908", "0x9964"]


def pd(img, addr, n):
    out = subprocess.run(RIZIN + ["-c", "pdj %d @ %d" % (n, addr), IMG[img]],
                         capture_output=True, text=True, timeout=120).stdout.strip()
    return json.loads(out) if out else []


def imms(opcode):
    """Non-branch, non-memory-literal immediate/constant values of one insn."""
    m = opcode.split()[0]
    if BRANCH.match(m.rstrip("s")):
        return []
    ops = opcode[len(m):]
    outside = MEM.sub(" ", ops)
    out = []
    for h in HEX.findall(outside):
        v = int(h, 16)
        if v < LEN["320"] or v >= 0x20000000:
            continue          # in-image pointer, SRAM pointer, MMIO
        out.append(v)
    disp = []
    for x in MEM.findall(ops):
        for h in HEX.findall(x):
            disp.append(int(h, 16))
    return out + disp


def main():
    d = json.load(open(os.path.join(OUT, "pairs_final.json")))
    pairs = {r["a_3112"]: r for r in d["pairs"]}
    meta = {p["a_3112"]: p for p in json.load(open(os.path.join(DELEG, "matcher/results_calibrated.json")))
            ["pairs_3112_320"]["unique_1to1"]}
    detail = {}
    for sel in SEL:
        p = meta[sel]
        a = pd("3112", int(p["a_3112"], 16), p["n_3112"])[:p["n_3112"]]
        b = pd("320", int(p["b_320"], 16), p["n_320"])[:p["n_320"]]
        print("\n### PAIR %s -> %s  (%d/%d insns, %d/%d B, s=%.6f)"
              % (p["a_3112"], p["b_320"], p["n_3112"], p["n_320"],
                 p["size_3112"], p["size_320"], p["s"]))
        # context windows: +-3 around each changed index (index-wise) or difflib opcodes
        if pairs[sel]["mnem_seq_equal"]:
            idx = [c["idx"] for c in pairs[sel]["changes"]
                   if set(c["kinds"]) - {"target"}]
            ch = pairs[sel]["changes"]
        else:
            idx = []
            ch = []
        if idx:
            lo, hi = max(0, min(idx) - 3), min(len(a), max(idx) + 4)
            for i in range(lo, hi):
                mark = "*" if i in idx else " "
                print("%s %3d  %04x  %-34s | %04x  %s"
                      % (mark, i, a[i]["offset"], a[i]["opcode"], b[i]["offset"], b[i]["opcode"]))
            detail[sel] = {"mode": "index", "lo": lo, "hi": hi,
                           "old": [{"off": hex(a[i]["offset"]), "op": a[i]["opcode"], "bytes": a[i]["bytes"]} for i in range(lo, hi)],
                           "new": [{"off": hex(b[i]["offset"]), "op": b[i]["opcode"], "bytes": b[i]["bytes"]} for i in range(lo, hi)],
                           "changed_idx": idx}
        else:
            import difflib
            sm = difflib.SequenceMatcher(None, [i["opcode"].split()[0] for i in a],
                                         [i["opcode"].split()[0] for i in b], autojunk=False)
            wins = []
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                if tag == "equal":
                    continue
                lo, hi = max(0, i1 - 3), min(len(a), i2 + 3)
                lo2, hi2 = max(0, j1 - 3), min(len(b), j2 + 3)
                print("  [%s] old[%d:%d] new[%d:%d]  tag=%s" % (tag, i1, i2, j1, j2, tag))
                for k in range(max(hi - lo, hi2 - lo2)):
                    oi, ni = lo + k, lo2 + k
                    so = ("%04x  %-32s" % (a[oi]["offset"], a[oi]["opcode"])) if oi < hi else ""
                    sn = ("%04x  %s" % (b[ni]["offset"], b[ni]["opcode"])) if ni < hi2 else ""
                    print("      %-40s | %s" % (so, sn))
                wins.append({"tag": tag, "i": [i1, i2], "j": [j1, j2],
                             "old": [{"off": hex(a[k]["offset"]), "op": a[k]["opcode"], "bytes": a[k]["bytes"]} for k in range(i1, min(len(a), i2 + 3))],
                             "new": [{"off": hex(b[k]["offset"]), "op": b[k]["opcode"], "bytes": b[k]["bytes"]} for k in range(j1, min(len(b), j2 + 3))]})
            detail[sel] = {"mode": "opcode_windows", "windows": wins}

    # decoded constant cross-check
    tot_diff, diff_pairs = 0, []
    for k, p in meta.items():
        a = pd("3112", int(p["a_3112"], 16), p["n_3112"])[:p["n_3112"]]
        b = pd("320", int(p["b_320"], 16), p["n_320"])[:p["n_320"]]
        ca = collections.Counter(v for i in a for v in imms(i["opcode"]))
        cb = collections.Counter(v for i in b for v in imms(i["opcode"]))
        if ca != cb:
            tot_diff += 1
            diff_pairs.append({"a": p["a_3112"], "b": p["b_320"],
                               "only_old": [hex(x) for x in sorted(set(ca) - set(cb))],
                               "only_new": [hex(x) for x in sorted(set(cb) - set(ca))]})
    print("\n### decoded non-pointer constant multiset differs in %d / 155 pairs" % tot_diff)
    for x in diff_pairs:
        print("   ", x["a"], x["b"], "old_only", x["only_old"], "new_only", x["only_new"])
    json.dump({"selected": detail, "const_diff_pairs": diff_pairs},
              open(os.path.join(OUT, "windows12.json"), "w"), indent=1)


if __name__ == "__main__":
    main()
