#!/usr/bin/env python3
"""Parse `hpmdiagnose` raw register dumps into structured JSON + a per-RID table.

Input: text captured from /usr/bin/hpmdiagnose (four "HPM at RID ..." blocks,
each a list of  reg  len  hexpayload  lines).

Usage: hpm_regs.py evidence/hpmdiagnose-raw.txt out.json
"""
import json
import re
import sys


def parse(path):
    rids = {}
    cur = None
    for line in open(path, errors="replace"):
        line = line.rstrip("\n")
        m = re.match(r"HPM at RID (0x[0-9a-f]+) Route (0x[0-9a-f]+) Address (0x[0-9a-f]+)", line)
        if m:
            cur = {"rid": m.group(1), "route": m.group(2), "addr": m.group(3), "regs": {}}
            rids[cur["rid"]] = cur
            continue
        m = (re.match(r"^(0x[0-9a-f]+)\t0x([0-9a-fA-F]+)\t0x([0-9A-F]+)$", line)
             or re.match(r"^'(\w+)'\t0x([0-9a-fA-F]+)\t0x([0-9A-F]+)$", line))
        if m and cur:
            cur["regs"][m.group(1)] = {"len": int(m.group(2), 16), "data": m.group(3)}
    return rids


def show(rids, reg):
    for rid in ("0x0", "0x1", "0x2", "0x5"):
        r = rids[rid]["regs"].get(reg)
        if not r:
            continue
        b = bytes.fromhex(r["data"])
        asc = "".join(chr(c) if 32 <= c < 127 else "." for c in b)
        print(f"RID {rid} reg {reg} len={r['len']}\n  {b.hex(' ')}\n  |{asc}|")


if __name__ == "__main__":
    rids = parse(sys.argv[1])
    json.dump(rids, open(sys.argv[2], "w"), indent=1)
    for k, v in rids.items():
        print(f"RID {k}: spmi_addr={v['addr']} regs={len(v['regs'])}")
    for reg in ("0x47", "0x49", "0x4a", "0x2f", "0x11"):
        show(rids, reg)
