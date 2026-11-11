#!/usr/bin/env python3
"""Emit the deliverable pair->classification JSON.

Classes come from pairs_final.json (pass 3). The five pairs whose canonical
mnemonic sequence is NOT equal were classified structurally by pass 3 as
"identical_instructions" (pass 3 had no changes list for them), so they are
re-labelled here from the decoded opcode windows in windows12.json. Each
override carries the instruction that justifies it.
"""
import json, os, collections

OUT = os.path.dirname(os.path.abspath(__file__))
d = json.load(open(os.path.join(OUT, "pairs_final.json")))

OVERRIDE = {
    "0x1178": ("instruction_sequence_edit",
               "old[16] 'ldr r0, [r5, 0x48]' deleted; new loads the base into r0 "
               "and compares r1 against r5 (0x1198-0x11a0 vs 0x11c0-0x11c6)"),
    "0x1df0": ("instruction_sequence_edit",
               "new inserts 'ldr r0,[r6,0x6c]; movs r1,8; bics r0,r1; str r0,[r6,0x6c]' "
               "at entry (0x1d78-0x1d7e); tail windows are a decoder desync, see semantics.md"),
    "0xa018": ("condition_signedness_change",
               "'ble'->'bls' at a02c/a034 and 'bgt'->'bhi' at a042/a04a, each after "
               "'cmp r4, r0'"),
    "0xbb4c": ("indexed_load_replaces_fixed_offset_load",
               "old 0x18 fixed displacement 'ldrb r0,[r0,0x18]' replaced by "
               "'movs r0,0x20; ldr r1,[pc,0x9c]; ldrb r0,[r1,r0]' (bc7c-bc88)"),
    "0xcf38": ("instruction_reordering",
               "'cmp r0,0' and 'ldr r2,[pc,...]' swapped (cf8a-cf8e vs d11a-d11e); "
               "no other change in the pair"),
}

out = []
for r in d["pairs"]:
    cls = r["class"]
    note = ""
    if r["a_3112"] in OVERRIDE:
        cls, note = OVERRIDE[r["a_3112"]]
    out.append({
        "a_3112": r["a_3112"], "b_320": r["b_320"], "s": r["s"],
        "size_3112": r["size_3112"], "size_320": r["size_320"],
        "n_3112": r["n_3112"], "n_320": r["n_320"],
        "class": cls,
        "mnem_seq_equal": r["mnem_seq_equal"],
        "n_decoded_changes": len(r["changes"]),
        "change_kinds": r["kind_counts"],
        "const_multiset_rawword_equal": r["words"]["const_multiset_equal"],
        "evidenced_by": note or ("; ".join("%s: %s -> %s" % (c["old_off"], c["old"], c["new"])
                                           for c in r["changes"]
                                           if set(c["kinds"]) - {"target"}) or
                                "no non-target operand change"),
    })
agg = collections.Counter(x["class"] for x in out)
json.dump({"pairs": out, "class_counts": dict(agg),
           "n_pairs": len(out),
           "n_with_any_decoded_diff": sum(1 for x in out if x["n_decoded_changes"] or not x["mnem_seq_equal"]),
           "n_with_semantic_non_relink_diff": sum(1 for x in out if x["class"] not in
                                                 ("identical_instructions",
                                                  "identical_modulo_target_relink"))},
          open(os.path.join(OUT, "results_pair_class.json"), "w"), indent=1)
print(json.dumps(dict(agg), indent=1, sort_keys=True))
print(json.dumps({k: v for k, v in json.load(open(os.path.join(OUT, "results_pair_class.json"))).items()
                  if k != "pairs"}, indent=1))
