# BootKC extraction: methodology, validation, limitations

Source: `/System/Volumes/Preboot/9063E54E-.../boot/BBF65A7E.../System/Library/Caches/com.apple.kernelcaches/kernelcache`
sha256 `16398f6296e617a4d5116867ace2925c49a2a3a5f333886be5ff6055a90ae4ae`, 32,585,486 bytes.

## Pipeline

1. IMG4 container: `SEQUENCE { IA5String "IMG4", SEQUENCE { IA5String "IM4P", IA5String "krnl",
   IA5String "KernelManagement_host-514.40.8", OCTET STRING payload } }`.
   Payload begins at file offset 0x44, length 0x01F111CB = 32,575,947.
2. Payload magic `62 76 78 32` ("bvx2") = LZFSE. Decompresses to 123,961,344 bytes,
   magic `cf fa ed fe`, cputype `0x0100000c` (arm64).
3. The decompressed image is a Mach-O *fileset* (`filetype` 12) with 369
   `LC_FILESET_ENTRY` (0x80000035) entries, one per kext.
4. `scripts/kc_fileset_extract.py` repacks each module.

## Why repacking is required

Segment placement in a BootKC is not contiguous per module. For
`com.apple.driver.AppleHPM` (RID-bearing USB-C PD controller driver):

| segment | vmaddr | filesize |
|---|---|---|
| __TEXT | 0xfffffe00074b6440 | 0x142c0 |
| __TEXT_EXEC | 0xfffffe00094cb090 | 0x5a108 |
| __DATA | 0xfffffe000cab5bb8 | 0x1054 |
| __DATA_CONST | 0xfffffe00081053d8 | 0x22b40 |
| __LINKEDIT | 0xfffffe000cd5c000 | 0x18da2b7 |

Only `__TEXT` sits at the `LC_FILESET_ENTRY` fileoff (0x4b2440). `__TEXT_EXEC` is
33 MB further on, `__DATA` at 90 MB, `__DATA_CONST` at 12 MB. A naive slice plus
fileoff subtraction therefore produces a Mach-O whose segments point outside the
file. `otool -l` reports `fileoff ... past end of file`.

The extractor copies each segment's bytes into a new file and rewrites
`LC_SEGMENT_64.fileoff` and each `section_64.offset`. Virtual addresses are
preserved verbatim, so any address from disassembly maps directly onto the
running kernel.

## Validation performed

- Every rebased segment fileoff and section offset is checked against the output
  file size; a rebased offset that is negative or past EOF is zeroed and reported
  as a `LIMITATION:` line. No wraparound and no `& 0xFFFFFFFF` masking.
- Section bytes in the repacked file were compared against the source
  kernelcache at their absolute offsets: `__text` (0x597b8), `__cstring`
  (0x138e7), `__data` (0x9c9), `__mod_init_func` (0x140) all byte-identical.
- `LC_SYMTAB` survives repacking: 2588 symbols, 524 of them
  `AppleHPMInterface*`, including `__ZN17AppleHPMInterface18isCableKartCapableEv`.
- All 5 segments report `within_file=True`.

## Known limitations (accepted, not to be "fixed")

1. `__LINKEDIT` is page-shared across kexts in a BootKC, so the repacked module
   copies a 26 MB `__LINKEDIT` that mostly belongs to other kexts. Files are
   ~26 MB despite 82 KB of `__TEXT`. Wasteful, not incorrect.
2. `LC_DYSYMTAB` symbol *indices* (`ilocalsym`, `iextdefsym`, ...) index the
   kernelcache-wide symbol table, not this module's `LC_SYMTAB`. Rebased offsets
   in that command can land outside the repacked file, so the command is zeroed.
   Consequence: `rz-bin -sj` reports 1672 of the 2588 symbols (it splits by
   dysymtab). The authoritative count from `LC_SYMTAB` is 2588. Use
   `LC_SYMTAB`/`nm`-style reads, rizin, or Ghidra, not the dysymtab-split view.
3. `strings(1)` and `otool` may refuse the file because of limitation 2. Read
   strings through `rz-bin -zj` or a raw byte grep.
4. Code signatures are invalid for the repacked files. They are analysis
   artifacts only and must never be loaded into a kernel.
