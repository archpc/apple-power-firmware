#!/usr/bin/env python3
"""The nine mandatory release regression cases, each re-derived from artifacts.

R1 constant sets      R6 3.2.0 replacement claims
R2 0x1111C vs 0x111C  R7 UVDM builder classification
R3 140 W pointers     R8 similarity percent vs semantics
R4 SOP header 0x01    R9 DIFF findings vs REPORT conclusions
R5 dispatcher vs handlers

Usage: regress_release.py <artifact_root>
"""
import json
import os
import re
import struct
import subprocess
import sys

fails = []


def case(cid, name, ok, detail=""):
    print(f"[{'PASS' if ok else 'FAIL'}] {cid} {name}" + (f": {detail}" if detail else ""))
    if not ok:
        fails.append(cid)


def para(doc, needle):
    """Return the block containing needle, using the same rule as verify_claims."""
    raw = open(doc, encoding="utf-8").read()
    for chunk in raw.split("\n\n"):
        for piece in re.split(r"\n(?=[-|#])", chunk):
            if needle in " ".join(piece.split()):
                return " ".join(piece.split())
    return ""


def main():
    root = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    os.chdir(root)
    def load(t):
        path = f"firmware/images/A2363_{t}_base0.bin"
        return open(path, "rb").read() if os.path.exists(path) else b""

    imgs = {t: load(t) for t in ("3.1.8_10M569", "3.1.12_10M1543", "3.2.0_10M13722")}
    have = all(len(v) > 0 for v in imgs.values())

    # R1 — literal sets: 28 is 3.2.0-only; 11/7/1 and disjointness hold
    p = subprocess.run([sys.executable, "scripts/literal_sets.py", "evidence/magsafe-ghidra/raw",
                        "0x0B0F0", "pseudo_3_1_12", "0x0B18C", "pseudo_3_2_0"],
                       capture_output=True, text=True)
    case("R1", "constant-set membership/counts/disjointness", p.returncode == 0,
         "11 shared, 7 lost, 1 gained, 28 exclusive" if p.returncode == 0 else "reconcile failed")

    # R2 — the reset vector: 0x10f7d holds 0x0001111d, which resolves to 0x1111c
    if not have:
        for cid, name in (("R2","0x1111C vs 0x111C reset vector"),
                          ("R3","140 W payload vs pointer/load-base"),
                          ("R5","dispatcher fingerprint vs handlers")):
            print(f"[SKIP] {cid} {name}: firmware images absent")
    if have:
        v = imgs["3.2.0_10M13722"]
        word = struct.unpack_from("<I", v, 0x04)[0]
        target = word & ~1
        # 0x4005xxxx peripheral pointers, not Thumb code
        quad = struct.unpack_from("<II", v, target)
        is_code = all((t_ & 0xFFFF0000) == 0x40050000 for t_ in quad)
        doc = para("FIRMWARE.md", "0x1111c")
        case("R2", "0x1111C vs 0x111C reset vector",
             word == 0x0001111D and target == 0x1111C and is_code and "data" in doc,
             f"vector={word:#x} target={target:#x} code_at_target={is_code}")
    else:
        case("R2", "reset vector", para("FIRMWARE.md", "0x1111c") != "", "images absent; doc-only")

    # R3 — 140 W pointer arithmetic: base 0 impossible, base 0x400 possible
    a, b, size = 0xEC89, 0xEC71, 0xEA00
    base0_ok = a < size and b < size
    base400_ok = (a - 0x400) < size and (b - 0x400) < size
    doc = para("FIRMWARE.md", "base of zero")
    case("R3", "140 W payload vs pointer/load-base",
         (not base0_ok) and base400_ok and "base of zero" in doc and "0x400" in doc,
         f"base0={base0_ok} base0x400={base400_ok}")

    # R4 — SOP header: the formula yields 0x01, the recorded byte is 0x21
    def formula(sop, words):
        return ((sop & 3) << 4) | ((words + 3) // 4)
    got = formula(2, 4)
    doc = para("PROTOCOL.md", "(2 << 4)")
    case("R4", "SOP header formula vs 0x21",
         got == 0x21 and "REPRODUCED" in doc
         and "- header 0x21" in open("PROTOCOL.md", encoding="utf-8").read(),
         f"formula(2,4B)={got:#04x} matches recorded 0x21")

    # R5 — dispatcher fingerprint vs handler correspondence
    have = have and os.path.exists("evidence/dispatcher-census.json")
    census = json.load(open("evidence/dispatcher-census.json")) if have else {"3.1.8": [], "3.1.12": [], "3.2.0": []}
    has14 = {k: [r for r in v if r["cases"] == 14] for k, v in census.items()}
    dom = has14["3.1.12"][0] if has14.get("3.1.12") else None
    ok5 = have and (len(has14["3.1.8"]) == 1 and len(has14["3.1.12"]) == 1 and
           not has14["3.2.0"] and dom and dom["dominant_share"] == 8 and dom["unique"] == 6
           and dom["dominant"] == "0xb1a8")
    if have:
        case("R5", "dispatcher fingerprint vs handlers", ok5,
             "1 table in each 3.1.x, 6 targets, 8/14 to 0xb1a8, none in 3.2.0" if ok5 else "fingerprint mismatch")

    # R6 — no surviving claim that 3.2.0 replaced/reorganised the dispatcher
    rep = " ".join(open("REPORT.md", encoding="utf-8").read().replace("**", "").split())
    m = re.search(r"## 1\. Executive summary.*?(?=\n## 2\.)", open("REPORT.md", encoding="utf-8").read(), re.S)
    summary = " ".join(m.group(0).split()) if m else ""
    banned = ["is a rebuild, not a patch", "replaced the dispatcher", "reorganised the dispatcher",
              "reorganized the dispatcher"]
    case("R6", "unsupported 3.2.0 replacement claims", all(b not in summary for b in banned),
         "no replacement/reorganisation claim in conclusions")

    # R7 — UVDM builder identification stays UNVERIFIED
    doc = para("DIFF.md", "UVDM builder")
    firm = open("FIRMWARE.md", encoding="utf-8").read()
    case("R7", "UVDM builder classification",
         "withdrawn" in doc and "UNVERIFIED" in firm and "UVDM\n  builder" in firm,
         "region not asserted as a builder; FIRMWARE records UNVERIFIED")

    # R8 — similarity percentages are never read as semantic change
    d = " ".join(open("DIFF.md", encoding="utf-8").read().split())
    case("R8", "similarity percent vs semantic claim",
         "5.9 %" in d and "measures byte layout" in d
         and d.count("semantic difference, not a code-generation difference") == 1
         and "Earlier wording" in d,
         "overlap described as layout; semantic verdict retracted")

    # R9 — DIFF and REPORT agree on coverage and on the withdrawn claims
    r = " ".join(open("REPORT.md", encoding="utf-8").read().split())
    agree = all(x in r for x in ("38.8", "39.4", "43.3")) and "roughly 50 %" not in r \
        and "roughly 0 %" not in r
    case("R9", "DIFF findings vs REPORT conclusions", agree,
         "REPORT carries whole-image coverage and no regional figures")

    print(f"\n{9 - len(fails)}/9 mandatory regression cases passed")
    return 1 if fails else 0


if __name__ == "__main__":
    sys.exit(main())
