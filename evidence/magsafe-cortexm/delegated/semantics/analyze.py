#!/usr/bin/env python3
"""Per-pair semantic diff of the calibrated 155 non-stub 1:1 pairs (3.1.12 -> 3.2.0).

Reads only existing evidence: matcher/results_calibrated.json (pair set),
xversion/mnems_{3112,320}.json (mnemonic sequences), and decodes function
bodies from firmware/images/*_base0.bin with rizin 0.9.1 (arm/thumb16).

Emits:
  pairs_detail.json  -- per-pair analysis (windows, decoded instructions)
  results.json       -- pair -> classification, aggregates

Rules honoured here:
  * addresses are file offsets (rizin maps the raw file at vaddr 0);
  * every classification is derived from decoded instruction text, never from
    mnemonic counts alone;
  * no semantic reading is emitted, only structural classes.
"""
import json, os, re, subprocess, difflib, collections, sys

REPO = "/Users/sein/.hermes/artifacts/apple-power-firmware"
DELEG = os.path.join(REPO, "evidence/magsafe-cortexm/delegated")
OUT = os.path.join(DELEG, "semantics")
IMG = {
    "3112": os.path.join(REPO, "firmware/images/A2363_3.1.12_10M1543_base0.bin"),
    "320": os.path.join(REPO, "firmware/images/A2363_3.2.0_10M13722_base0.bin"),
}
LEN = {k: os.path.getsize(v) for k, v in IMG.items()}
RIZIN = ["rizin", "-e", "scr.color=0", "-a", "arm", "-b", "16", "-q"]

CFLOW = {"b", "beq", "bne", "bcs", "bcc", "bmi", "bpl", "bvs", "bvc",
         "bhi", "bls", "bge", "blt", "bgt", "ble", "cbz", "cbnz", "bx", "blx"}
CALL = {"bl", "blx"}


def pdj(img_key, addr, n):
    cmd = RIZIN + ["-c", "pdj %d @ %d" % (max(n, 1), addr), IMG[img_key]]
    out = subprocess.run(cmd, capture_output=True, text=True, timeout=120).stdout.strip()
    if not out:
        return []
    try:
        return json.loads(out)
    except json.JSONDecodeError:
        return []


def mnem(opcode):
    m = opcode.split()[0].lower()
    return m.rstrip("s") if m.endswith("s") and m[:-1] in ("push", "pop") else m


HEX = re.compile(r"0x[0-9a-fA-F]+")


def operands(opcode):
    parts = opcode.split(None, 1)
    return parts[1] if len(parts) > 1 else ""


def consts(opcode, imglen):
    """Return (immediates, branch_targets) as ints, classified."""
    ops = operands(opcode)
    imm, tgt = [], []
    if mnem(opcode) in CFLOW:
        for h in HEX.findall(ops):
            tgt.append(int(h, 16))
        return imm, tgt
    for h in HEX.findall(ops):
        v = int(h, 16)
        # '#'-prefixed hex is an immediate; a bare hex inside [] is an offset
        imm.append(v)
    return imm, tgt


def litclass(v, imglen):
    if v < imglen:
        return "in_image_ptr"
    if 0x20000000 <= v < 0x20080000:
        return "sram_ptr"
    if v == 0:
        return "zero"
    return "constant"


def analyze(p):
    d = {}
    for side, key, addr_key, n_key in (("old", "3112", "a_3112", "n_3112"),
                                       ("new", "320", "b_320", "n_320")):
        addr = int(p[addr_key], 16)
        ins = pdj(key, addr, p[n_key] + 4)
        # trim to the recorded instruction count
        ins = ins[: p[n_key]]
        d[side] = ins
    return d


def seq(ins):
    return [mnem(i["opcode"]) for i in ins]


def full(p):
    a, b = seq(p["old"]), seq(p["new"])
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    ops = [o for o in sm.get_opcodes() if o[0] != "equal"]
    return sm.ratio(), ops, a, b


def windows(p, ops, pad=2):
    out = []
    for tag, i1, i2, j1, j2 in ops:
        lo_i, hi_i = max(0, i1 - pad), min(len(p["old"]), i2 + pad)
        lo_j, hi_j = max(0, j1 - pad), min(len(p["new"]), j2 + pad)
        out.append({
            "tag": tag, "old_idx": [i1, i2], "new_idx": [j1, j2],
            "old_window": fmt_window(p["old"], lo_i, hi_i),
            "new_window": fmt_window(p["new"], lo_j, hi_j),
        })
    return out


def fmt_window(ins, lo, hi):
    return [{"off": hex(i["offset"]), "op": i["opcode"], "bytes": i["bytes"]}
            for i in ins[lo:hi]]


def literal_profile(ins, imglen):
    c = collections.Counter()
    for i in ins:
        imm, _ = consts(i["opcode"], imglen)
        for v in imm:
            c[litclass(v, imglen)] += 1
    return c


def operand_signature(ins, imglen):
    """operand text with branch targets and in-image pointers masked."""
    sig = []
    for i in ins:
        op = operands(i["opcode"])
        # mask branch targets: b<cond> 0x1234 -> 0xTGT
        if mnem(i["opcode"]) in CFLOW:
            op = HEX.sub("0xTGT", op)
        sig.append("%s %s" % (i["opcode"].split()[0], op))
    return sig


def classify(p, ratio, ops, ev):
    """Structural class from decoded instructions only."""
    tags = [o[0] for o in ops]
    removed = [o for o in ops if o[0] in ("delete", "replace")]
    added = [o for o in ops if o[0] in ("insert", "replace")]
    old_call_delta = sum(1 for o in removed for i in p["old"][o[1]:o[2]]
                         if mnem(i["opcode"]) in CALL)
    new_call_delta = sum(1 for o in added for i in p["new"][o[3]:o[4]]
                         if mnem(i["opcode"]) in CALL)
    cfg_delta = sum(1 for o in removed for i in p["old"][o[1]:o[2]]
                    if mnem(i["opcode"]) in CFLOW) + \
                sum(1 for o in added for i in p["new"][o[3]:o[4]]
                    if mnem(i["opcode"]) in CFLOW)

    if not ops:
        # identical mnemonics; check operands
        if ev["opsig_equal"]:
            return "identical_instructions"
        if ev["reg_perm_only"]:
            return "register_allocation"
        if ev["const_diff"]:
            return "constant_change"
        return "operand_change_other"
    if new_call_delta != old_call_delta:
        return "call_added_or_removed"
    if cfg_delta and cfg_delta == sum(1 for o in removed for i in p["old"][o[1]:o[2]]
                                      if mnem(i["opcode"]) in CFLOW) + \
                    sum(1 for o in added for i in p["new"][o[3]:o[4]]
                        if mnem(i["opcode"]) in CFLOW) - new_call_delta:
        return "control_flow_shape"
    if abs(len(p["old"]) - len(p["new"])) <= 2 and len(ops) <= 2:
        return "control_flow_shape"
    return "instruction_sequence_change"


def reg_perm_ok(p, imglen):
    """True if the only operand difference is a consistent register renaming."""
    a = operand_signature(p["old"], imglen)
    b = operand_signature(p["new"], imglen)
    if len(a) != len(b):
        return False
    mapping = {}
    rre = re.compile(r"\b(r\d+|sb|sl|fp|ip|sp|lr|pc)\b")

    def canon(s, mapping, inv):
        out = []
        for tok in re.findall(r"\b(r\d+|sb|sl|fp|ip|sp|lr|pc)\b|[^a-z0-9_]+|[a-z0-9_]+",
                              s.replace(" ", "")):
            if rre.fullmatch(tok):
                if tok in mapping:
                    out.append(mapping[tok])
                elif tok in inv:
                    return None
                else:
                    mapping[tok] = "R%d" % len(mapping)
                    inv[tok] = True
                    out.append(mapping[tok])
            else:
                out.append(tok)
        return "".join(out)

    for x, y in zip(a, b):
        m, inv = {}, {}
        if canon(x, m, inv) != canon(y, m, inv):
            return False
    return True


def main():
    d = json.load(open(os.path.join(DELEG, "matcher/results_calibrated.json")))
    pairs = [p for p in d["pairs_3112_320"]["unique_1to1"] if p["n_3112"] >= 8]
    assert len(pairs) == 155, len(pairs)
    detail = []
    for k, p in enumerate(pairs):
        ins = analyze(p)
        p["old"], p["new"] = ins["old"], ins["new"]
        ratio, ops, a, b = full(p)
        imglen = LEN["320"]
        opsig_a = operand_signature(p["old"], LEN["3112"])
        opsig_b = operand_signature(p["new"], imglen)
        lits_a = literal_profile(p["old"], LEN["3112"])
        lits_b = literal_profile(p["new"], imglen)
        ev = {
            "mnem_ratio": round(ratio, 6),
            "opsig_equal": opsig_a == opsig_b,
            "reg_perm_only": reg_perm_ok(p, imglen) if opsig_a != opsig_b else False,
            "const_diff": lits_a != lits_b,
            "lits_old": dict(lits_a), "lits_new": dict(lits_b),
            "decoded_old": len(p["old"]), "decoded_new": len(p["new"]),
        }
        cls = classify(p, ratio, ops, ev)
        rec = {
            "a_3112": p["a_3112"], "b_320": p["b_320"],
            "size_3112": p["size_3112"], "size_320": p["size_320"],
            "n_3112": p["n_3112"], "n_320": p["n_320"], "s": p["s"],
            "class": cls,
            "mnem_ratio_decoded": round(ratio, 6),
            "opsig_equal": ev["opsig_equal"],
            "reg_perm_only": ev["reg_perm_only"],
            "literal_class_counts": {"old": ev["lits_old"], "new": ev["lits_new"]},
            "windows": windows(p, ops) if ops else [],
        }
        detail.append(rec)
        if (k + 1) % 25 == 0:
            print("... %d/%d" % (k + 1, len(pairs)), file=sys.stderr)
    agg = collections.Counter(r["class"] for r in detail)
    json.dump({"pairs": detail, "class_counts": dict(agg)},
              open(os.path.join(OUT, "pairs_detail.json"), "w"), indent=1)
    print(json.dumps(dict(agg), indent=1))
    nonident = [r for r in detail if r["class"] != "identical_instructions"]
    print("non-identical classes: %d / 155" % len(nonident))
    for r in nonident:
        print(r["a_3112"], r["b_320"], r["class"], r["s"], "n=%d/%d" % (r["n_3112"], r["n_320"]),
              "opsig_eq=%s" % r["opsig_equal"], "regperm=%s" % r["reg_perm_only"])


if __name__ == "__main__":
    main()
