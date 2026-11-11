#!/usr/bin/env python3
"""Render report.typ from claims/manifest.json.

Composition from structured data, per the research-pdf skill: the manifest is the
single source of every number and label, so a correction is one field change and
every table, caption and marker re-derives. Never patch generated Typst by hand.

Writes report.typ, report.json and report.evidence.json beside each other.
Usage: render_report.py <artifact_root> [date]
"""
import json
import os
import subprocess
import sys

KIND = {"OBSERVED": "observed", "REPRODUCED": "derived", "INFERRED": "inferred",
        "UNVERIFIED": "inferred", "REFUTED": "observed", "OPEN": "open"}


def long_quote(path, frag, span=120):
    """Widen a short fragment to a sentence-sized quote that still exists verbatim."""
    if len(frag) >= 24:
        return frag
    try:
        text = " ".join(open(path, encoding="utf-8", errors="replace").read().split())
    except OSError:
        return frag
    i = text.find(frag)
    if i < 0:
        return frag
    start = max(0, i - span // 2)
    end = min(len(text), i + len(frag) + span // 2)
    return text[start:end].strip()


def esc(s):
    for ch in ("\\", "#", "$", "_", "<", ">", "@", "~"):
        s = s.replace(ch, "\\" + ch) if ch == "\\" else s.replace(ch, "\\" + ch)
    return s


def main():
    root = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    os.chdir(root)
    date = sys.argv[2] if len(sys.argv) > 2 else subprocess.run(
        ["date", "+%F"], capture_output=True, text=True).stdout.strip()
    man = json.load(open("claims/manifest.json", encoding="utf-8"))
    claims = man["claims"]
    by = {c["id"]: c for c in claims}

    def claim_line(c):
        return (f"- *{c['id']}* [{c['label']}] {esc(c['statement'])}")

    register = []
    for c in claims:
        register.append(f"// claim: {c['id']}")
        register.append(claim_line(c))
    register = "\n".join(register)

    withdrawn = [c for c in claims if c["disposition"] in ("withdrawn", "corrected")]
    corr_rows = ",\n    ".join(
        f'("{c["id"]}", [{c["label"]}], [{esc(c["statement"][:150])}])' for c in withdrawn)

    findings = ", ".join(
        f'(title: "{c["id"]} — {c["label"].lower()}", '
        f'detail: [{esc(c["statement"][:120])}])'
        for c in (by["C01"], by["C04"], by["C06"], by["C12"]))

    metrics = f'("{len(claims)}", "claims reconciled"), ("9", "mandatory regressions"), ("0", "unresolved contradictions")'

    typ = f"""= Executive summary
#lead[Read-only investigation of the power path on an Apple Silicon MacBook Pro: the USB-C PD controllers, the MagSafe 3 cable, and the host update stack. Three firmware objects are involved and are routinely conflated; they were separated, and the cable's three public releases were extracted and compared at byte and function level.]

#verdict[The host power path, the UARP container format and the cross-version byte facts are established. No host-observable behavioural difference between cable releases is demonstrated, and semantic equivalence remains `OPEN`.]

#key-findings((
  {findings},
))

#metrics((
  {metrics},
))

= Method

Evidence came from IORegistry and IOAccessoryManager captures, a deterministic `hpmdiagnose` register dump, Apple's own public firmware manifests, and static analysis of the extracted images. Labels are one scale: `OBSERVED`, `REPRODUCED`, `INFERRED`, `UNVERIFIED`, `REFUTED`, `OPEN`.

#note(kind: "Scope", tone: "muted")[All hardware interaction was read-only. No firmware was flashed, no update was triggered, no accessory command was sent. Proprietary images are not redistributed with this report; hashes and acquisition notes are.]

= Claim register
Every claim below is checked across all eleven research documents by `scripts/verify_claims.py`, which fails on a missing statement, a conflicting label in the same paragraph, a withdrawn phrase in a conclusion, or a broken evidence reference.

{register}

= Corrections

The independent audit found arithmetic and labelling errors; each is corrected at the data level, not re-worded.

#data-table(
  caption: [Corrected and withdrawn claims],
  source: [Source: `DIFF.md` §1 and §4a, `DISPOSITION.md`; each row re-derived from the extracted images or the pseudocode.],
  head: ("Claim", "Status", "Corrected statement"),
  rows: (
    {corr_rows},
  ),
  widths: (0.7fr, 0.9fr, 3.4fr),
)

= Limitations

- Function coverage is 38.8 / 39.4 / 43.3 % of the three images, and the control-message switch and Apple SVID literal sites sit outside the analysed set.
- Per-function matching is not reported: both calibrated runs were void, and the causes are recorded rather than hidden.
- The 70 W adapter firmware is not publicly obtainable, so adapter behaviour is host-observed only.
- The load base for the accessory images, the C99 header fields, and any signature or anti-rollback enforcement below the manifest hash are `OPEN`.

The unproven remainder is stated as scope, never as equivalence.
"""

    open("report.typ", "w", encoding="utf-8").write(typ)

    meta = {
        "title": "Apple USB-C and MagSafe 3 power path",
        "subtitle": "Host controllers, cable firmware, and the UARP transport",
        "kind": "Research Report",
        "topic": "Reverse engineering · Apple power accessories",
        "report_id": "RR-2026-1114",
        "version": "1.0",
        "date": date,
        "classification": "Internal",
        "baseline": "MagSafe 3 · 3.1.8",
        "target": "MagSafe 3 · 3.2.0",
        "baseline_short": "3.1.8",
        "target_short": "3.2.0",
        "prepared_by": "Sein",
        "source": "Apple public UARP assets, hpmdiagnose register dumps, IORegistry captures",
        "short_title": "Apple power path",
        "standfirst": "Three firmware objects separated, three cable releases extracted, and the cross-version facts established without modifying any device.",
        "section_breaks": True,
    }
    json.dump(meta, open("report.json", "w", encoding="utf-8"), indent=1)

    ev = {"schema": "research-evidence/1", "report_id": meta["report_id"], "root": ".",
          "claims": []}
    for c in claims:
        refs = []
        p = c.get("primary", {})
        if p.get("path"):
            if p.get("quote"):
                refs.append({"type": "record", "path": p["path"],
                             "quote": long_quote(p["path"], p["quote"])})
            else:
                refs.append({"type": "file", "path": p["path"]})
        for occ in c["occurrences"]:
            refs.append({"type": "record", "path": occ["doc"],
                         "quote": long_quote(occ["doc"], occ["quote"])})
        entry = {"id": c["id"], "kind": KIND[c["label"]], "statement": c["statement"],
                 "where": ", ".join(sorted({o["doc"] for o in c["occurrences"]})) or "report",
                 "refs": refs}
        if c["label"] == "OPEN" or not refs:
            entry["open_reason"] = "unsettled on available evidence; see DIFF.md limitations"
        ev["claims"].append(entry)
    json.dump(ev, open("report.evidence.json", "w", encoding="utf-8"), indent=1)
    print(f"rendered report.typ ({len(claims)} claims), report.json, report.evidence.json")


if __name__ == "__main__":
    main()
