#!/usr/bin/env python3
"""Extract integer-literal sets from two Ghidra pseudocode bodies and compare.

Rule (see DIFF.md §2): every integer literal is kept; a literal is dropped only
when the pseudocode dereferences or calls through the value. Relocations,
addresses and variable names are normalised away. 0 and 1 are reported separately
as trivial.

Usage: literal_sets.py <raw_dir> <addr_a> <pseudo_dir_a> <addr_b> <pseudo_dir_b>
Exit 0 when the printed counts reconcile, 1 otherwise.
"""
import os
import re
import sys

DEREF = re.compile(r"\*\s*\([^)]*\*\)\s*(0x[0-9a-fA-F]+)|\(code \*\)\s*(0x[0-9a-fA-F]+)"
                   r"|\(_func_[^)]*\)\s*(0x[0-9a-fA-F]+)")


def load(raw, pseudo_dir, addr):
    for name in (f"0x{addr:x}.c", f"0x{addr:X}.c"):
        path = os.path.join(raw, pseudo_dir, "functions", name)
        if os.path.exists(path):
            return "\n".join(l for l in open(path, errors="replace").read().splitlines()
                             if not l.startswith("//"))
    raise SystemExit(f"no pseudocode for 0x{addr:x} under {pseudo_dir}")


def literals(body):
    addrs = set()
    for m in DEREF.finditer(body):
        addrs.add(int(next(g for g in m.groups() if g), 16))
    out = set()
    for m in re.finditer(r"0x([0-9a-fA-F]+)", body):
        v = int(m.group(1), 16)
        if v not in addrs:
            out.add(v)
    for m in re.finditer(r"(?<![\w.x])(\d+)(?![\w.])", body):
        v = int(m.group(1))
        if v not in addrs:
            out.add(v)
    return out


def main():
    raw, a_addr, a_dir, b_addr, b_dir = sys.argv[1:6]
    ca = literals(load(raw, a_dir, int(a_addr, 0)))
    cb = literals(load(raw, b_dir, int(b_addr, 0)))
    inter = ca & cb
    only_a = ca - cb
    only_b = cb - ca
    trivial = {0, 1}
    print(f"a=0x{int(a_addr,0):x} literals={len(ca)}")
    print(f"b=0x{int(b_addr,0):x} literals={len(cb)}")
    print(f"intersection ({len(inter)}): {sorted(inter)}")
    print(f"only a ({len(only_a)}): {sorted(only_a)}")
    print(f"only b ({len(only_b)}): {sorted(only_b)}")
    shared_nt = sorted(inter - trivial)
    print(f"shared excluding trivial ({len(shared_nt)}): {shared_nt}")
    ok = (len(inter) == 13 and len(only_a) == 7 and len(only_b) == 1
          and only_b == {28} and 28 not in inter and len(shared_nt) == 11)
    print("RECONCILES" if ok else "DOES NOT RECONCILE")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
