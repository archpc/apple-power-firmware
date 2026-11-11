#!/usr/bin/env python3
"""Pass 2: field-level operand diff of the same 155 pairs.

Pass 1 (analyze.py) aligned mnemonics with difflib and compared whole operand
strings, which collapsed every operand change into an opaque "opsig" boolean and
mis-labelled a struct-displacement change as register allocation. Pass 2 aligns
the two decoded bodies index-wise (valid because 151/155 pairs have an identical
mnemonic sequence) and classifies each differing instruction field:

  reg        -- an ARM register name differs
  field      -- a memory displacement ([rX, 0xNN]) differs  -> struct/field offset
  imm        -- an immediate (#0xNN) differs
  target     -- a branch/call target differs (relink artefact)
  enc        -- neither field differs but encoded bytes do (encoding/width change)

Pair class is derived from the observed change types; when only `target`
differs the pair is `identical_modulo_target_relink`.
"""
import json, os, re, subprocess, collections, sys

REPO = "/Users/sein/.hermes/artifacts/apple-power-firmware"
DELEG = os.path.join(REPO, "evidence/magsafe-cortexm/delegated")
OUT = os.path.join(DELEG, "semantics")
IMG = {"3112": os.path.join(REPO, "firmware/images/A2363_3.1.12_10M1543_base0.bin"),
       "320": os.path.join(REPO, "firmware/images/A2363_3.2.0_10M13722_base0.bin")}
RIZIN = ["rizin", "-e", "scr.color=0", "-a", "arm", "-b", "16", "-q"]
REG = re.compile(r"\b(r(?:1[0-5]|[0-9])|sb|sl|fp|ip|sp|lr|pc)\b")
BRANCH = re.compile(r"^(b|bl|bx|blx|b[a-z]{1,2}|cbz|cbnz)$")


def pd(img, addr, n):
    out = subprocess.run(RIZIN + ["-c", "pdj %d @ %d" % (n, addr), IMG[img]],
                         capture_output=True, text=True, timeout=120).stdout.strip()
    return json.loads(out) if out else []


def fields(opcode):
    """Split an opcode into (mnemonic, [regs], [disp], [imm], [target])."""
    m = opcode.split()[0]
    ops = opcode[len(m):].strip()
    if BRANCH.match(m.rstrip("s")):
        return m, [], [], [], [h for h in re.findall(r"0x[0-9a-f]+", ops)]
    regs = REG.findall(ops)
    disp = re.findall(r"\[\s*r\w+\s*,\s*(0x[0-9a-f]+)", ops)
    regs_in_mem = re.findall(r"\[\s*(r\w+)", ops)
    imm = re.findall(r"#(-?0x[0-9a-f]+|-?\d+)", ops)
    return m, regs, disp + regs_in_mem, imm, []


def pairdiff(a, b):
    """Index-wise comparison. Returns list of per-instruction change records."""
    changes = []
    for i, (x, y) in enumerate(zip(a, b)):
        if x["opcode"] == y["opcode"]:
            continue
        mx, rx, dx, ix, tx = fields(x["opcode"])
        my, ry, dy, iy, ty = fields(y["opcode"])
        rec = {"idx": i, "old": x["opcode"], "new": y["opcode"],
               "old_off": hex(x["offset"]), "new_off": hex(y["offset"]),
               "kinds": []}
        if mx != my:
            rec["kinds"].append("mnemonic")
        if tx != ty:
            rec["kinds"].append("target")
            rec["target"] = [tx, ty]
        if ix != iy:
            rec["kinds"].append("imm")
            rec["imm"] = [ix, iy]
        if dx != dy:
            rec["kinds"].append("field")
            rec["field"] = [dx, dy]
        if rx != ry:
            rec["kinds"].append("reg")
            rec["reg"] = [rx, ry]
        if not rec["kinds"]:
            rec["kinds"].append("enc")
        changes.append(rec)
    return changes


def mnem_seq(ins):
    return [i["opcode"].split()[0] for i in ins]


def classify(changes):
    if not changes:
        return "identical_instructions"
    kinds = collections.Counter(k for c in changes for k in c["kinds"])
    kinds.pop("target", None) if set(kinds) == {"target"} else None
    if not kinds:
        return "identical_modulo_target_relink"
    if set(kinds) == {"target"}:
        return "identical_modulo_target_relink"
    if "mnemonic" in kinds and kinds["mnemonic"] == len(changes):
        return "instruction_sequence_change"
    if "field" in kinds and "imm" not in kinds and "mnemonic" not in kinds:
        return "struct_field_offset_change"
    if "imm" in kinds and "field" not in kinds and "mnemonic" not in kinds:
        return "immediate_change"
    if set(kinds) <= {"reg"}:
        return "register_allocation"
    return "mixed_" + "+".join(sorted(kinds))


def main():
    pairs = [p for p in json.load(open(os.path.join(DELEG, "matcher/results_calibrated.json")))
             ["pairs_3112_320"]["unique_1to1"] if p["n_3112"] >= 8]
    out = []
    for k, p in enumerate(pairs):
        a = pd("3112", int(p["a_3112"], 16), p["n_3112"])
        b = pd("320", int(p["b_320"], 16), p["n_320"])
        a, b = a[:p["n_3112"]], b[:p["n_320"]]
        rec = {"a_3112": p["a_3112"], "b_320": p["b_320"], "s": p["s"],
               "n_3112": p["n_3112"], "n_320": p["n_320"],
               "size_3112": p["size_3112"], "size_320": p["size_320"],
               "mnem_seq_equal": mnem_seq(a) == mnem_seq(b),
               "invalid_old": sum(1 for i in a if i["opcode"] == "invalid"),
               "invalid_new": sum(1 for i in b if i["opcode"] == "invalid")}
        if rec["mnem_seq_equal"]:
            ch = pairdiff(a, b)
            rec["changes"] = ch
        else:
            import difflib
            sm = difflib.SequenceMatcher(None, mnem_seq(a), mnem_seq(b), autojunk=False)
            rec["changes"] = []
            rec["windows"] = [{"tag": t, "old": [hex(i["offset"]) + " " + i["opcode"] for i in a[i1:i2]],
                               "new": [hex(j["offset"]) + " " + j["opcode"] for j in b[j1:j2]]}
                              for t, i1, i2, j1, j2 in sm.get_opcodes() if t != "equal"]
        rec["kind_counts"] = dict(collections.Counter(k for c in rec["changes"] for k in c["kinds"]))
        rec["class"] = classify(rec["changes"])
        out.append(rec)
        if (k + 1) % 40 == 0:
            print("...%d" % (k + 1), file=sys.stderr)
    agg = collections.Counter(r["class"] for r in out)
    json.dump({"pairs": out, "class_counts": dict(agg)},
              open(os.path.join(OUT, "pairs_detail2.json"), "w"), indent=1)
    print(json.dumps(dict(agg), indent=1, sort_keys=True))
    print("pairs with any decoded instruction difference:",
          sum(1 for r in out if r["class"] != "identical_instructions"))
    for r in out:
        if r["class"] not in ("identical_instructions", "identical_modulo_target_relink"):
            print(r["a_3112"], r["b_320"], r["class"], r["kind_counts"], "nchanges=%d" % len(r["changes"]))


if __name__ == "__main__":
    main()
