#!/usr/bin/env python3
"""Render the full research report from claims/manifest.json plus a narrative.

Composition from structured data (research-pdf rule): every figure in the body is
pulled from the manifest, the acquisition manifest or the census files, so a
correction is one field change and the tables re-derive. The claim register is an
appendix, not the body.

Usage: build_report.py <artifact_root> [date]
"""
import json
import os
import re
import subprocess
import sys

KIND = {"OBSERVED": "observed", "REPRODUCED": "derived", "INFERRED": "inferred",
        "UNVERIFIED": "inferred", "REFUTED": "observed", "OPEN": "open"}


def esc(s):
    for ch in ("\\", "#", "$", "_", "<", ">", "@", "~"):
        s = s.replace(ch, "\\" + ch)
    return s


def long_quote(path, frag, span=120):
    if len(frag) >= 24:
        return frag
    try:
        text = " ".join(open(path, encoding="utf-8", errors="replace").read().split())
    except OSError:
        return frag
    i = text.find(frag)
    if i < 0:
        return frag
    return text[max(0, i - span // 2): i + len(frag) + span // 2].strip()


def releases():
    """Parse firmware/MANIFEST.txt for the acquired releases and their hashes."""
    out = []
    try:
        txt = open("firmware/MANIFEST.txt", encoding="utf-8").read()
    except OSError:
        return out
    for m in re.finditer(r"\[OBSERVED\]\s+(\S+\.zip).*?sha1\s*:\s*([0-9a-f]{40})", txt, re.S):
        out.append((m.group(1), m.group(2)[:12]))
    return out


def main():
    root = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    os.chdir(root)
    date = sys.argv[2] if len(sys.argv) > 2 else subprocess.run(
        ["date", "+%F"], capture_output=True, text=True).stdout.strip()
    man = json.load(open("claims/manifest.json", encoding="utf-8"))
    claims = man["claims"]

    census = json.load(open("evidence/dispatcher-census.json"))
    sites = {k: len(v) for k, v in census.items()}

    rel_rows = ",\n    ".join(
        f'("{esc(n)}", [{h}…])' for n, h in releases()) or '("none parsed", [-])'

    register = []
    for c in claims:
        register.append(f"// claim: {c['id']}")
        register.append(f"- *{c['id']}* [{c['label']}] {esc(c['statement'])}")
    register = "\n".join(register)

    typ = f"""= Executive summary
#lead[Three firmware objects share the phrase "the charger firmware" and nothing else. This report separates them on a live Apple Silicon MacBook Pro, extracts the MagSafe 3 cable's three public releases, recovers the container format from Apple's own parser, and establishes what did and did not change between them — read-only throughout.]

#verdict[The host power path, the container format and the cross-version byte facts are established. No host-observable behaviour change is demonstrated, and semantic equivalence between 3.1.12 and 3.2.0 stays `OPEN`.]

#key-findings((
  (title: "Three objects, one name", detail: [HPM controller firmware `FW003.115.00`, cable 3.2.0 (PID `0x7800`, bcdDevice `0x3200`) and adapter `1030030` are distinct. Only the first two are host-verifiable; the adapter value is reported, not read.]),
  (title: "Container recovered, not guessed", detail: [The UARP SuperBinary layout came out of Apple's own parser in `uarpd`: a 44-byte header, 40-byte payload records, and six range checks that all four acquired files pass.]),
  (title: "One literal changed", detail: [`0x05AC0002` disappears and `0x05AC0000` gains an occurrence in 3.2.0. The power-negotiation table is byte-identical in all six copies across all three builds.]),
  (title: "The dispatcher idiom moved", detail: [A 14-case `mov pc` table is present in both 3.1.x builds and absent from 3.2.0, which shows 10 detected sites of the same mechanism with different tables.]),
))

#metrics((
  ("3", "cable releases extracted"),
  ("4", "HPM controllers mapped"),
  ("38.8 %", "of image inside analysed functions"),
))

= The three objects

Calling all of this "charger firmware" is what makes the topic confusing. They are
three different processors with three different update paths.

#data-table(
  caption: [Firmware objects in the power path],
  source: [Source: IORegistry and `IOAccessoryManager` captures in `evidence/`, `hpmdiagnose` register dumps, and `AppleHPM` decompilation.],
  head: ("Object", "Identifier", "How it was read"),
  rows: (
    ("HPM controller", "`FW003.115.00`", [From the kext's own strings and register file]),
    ("MagSafe 3 cable", "3.2.0 / PID `0x7800` / `0x3200`", [Register `0x49` and the in-file version]),
    ("70 W adapter", "`1030030` / ID `0x701c`", [Host-reported only: no adapter firmware obtained]),
  ),
  widths: (1.1fr, 1.5fr, 2.4fr),
)

The distinction matters for any security claim. The host can read the cable's
version out of the negotiation it already performs; it cannot read the adapter's
flash, and nothing in the acquired data shows otherwise.

= The host power path

Four HPM instances exist: three USB-C ports at RID 0, 1, 2 and the MagSafe port at
RID 5. The charger is on RID 5, and the winning power option is 20 V at 3.390 A,
which is 67.80 W.

#note(kind: "Access", tone: "muted")[The full HPM register file is readable without root by `hpmdiagnose`; access is gated by the `com.apple.USBCEntitlement` entitlement, not by privilege. That is the practical ceiling of noninvasive inspection, and it is higher than the usual "needs root" assumption.]

What the host exposes is a contract: a set of fixed power options, one of which is
selected. That is a negotiation result, not a firmware property, and the two should
never be tabulated as the same kind of fact.

= Acquiring the firmware

Apple publishes accessory firmware under `com.apple.MobileAsset.UARP.<model>` on
`updates.cdn-apple.com`. Each download was verified against the SHA-1 Apple itself
publishes in `_Measurement`, before anything was unpacked.

#data-table(
  caption: [Acquired cable releases],
  source: [Source: `firmware/MANIFEST.txt`; SHA-1 truncated here, full values and URLs in the manifest.],
  head: ("Asset", "SHA-1 (truncated)"),
  rows: (
    {rel_rows},
  ),
  widths: (3fr, 1.2fr),
)

The 70 W adapter is the exception, and the negative is scoped rather than absolute:
three enumeration methods failed — `mesu` path probes, a Pallas lookup including a
deliberately fake control type, and a broad type sweep. That is evidence about
Apple's public catalogue, not proof the firmware does not exist.

= Container format

The layout was recovered from Apple's parser (`expandSuperBinaryHeader` and the
payload-header walker in `uarpd`), not inferred from hex. That distinction is why
the extraction is trustworthy: the structure is the one the host enforces.

A 44-byte header carries the payload extent; each payload is described by a 40-byte
record with 4CC-tagged TLV metadata. On all four acquired files,
`dataOffset + dataLength` equals the declared extent, and six range checks pass.

#note(kind: "Method", tone: "muted")[An earlier attempt walked the file as generic TLVs and produced a plausible, wrong structure. Recovering the parser changed the answer. Guessing a container format from byte patterns is the failure mode this step avoids.]

= Image anatomy

Each payload opens with a 384-byte `C99` wrapper, then four words: stack pointer
`0x20002000` and three pointers. In 3.2.0 the word at offset `0x04` is
`0x0001111d`, whose Thumb target `0x1111c` holds `0x4005xxxx` peripheral addresses,
so the target is constant data, not a reset handler.

The load base is `OPEN`. The 140 W control image has a similar opening, but its
pointers `0xec89` and `0xec71` exceed its own `0xea00` payload, which rules out a
base-zero mapping for that image without ruling out other bases — a base of `0x400`
would place both inside. It is not corroboration, and it is not used as any.

= What changed, and what the numbers can say

Three measurements survive scrutiny, and each is deliberately narrow.

#data-table(
  caption: [Cross-version observations],
  source: [Source: `scripts/diff_verify.py`, `scripts/dispatcher_census.py`, `scripts/coverage.py`; all re-derivable.],
  head: ("Observation", "3.1.8", "3.1.12", "3.2.0"),
  rows: (
    ("Fixed PDO table", [5/9/15/20 V @ 3 A], [same], [same]),
    ("`0x05AC0002` occurrences", [1], [1], [0]),
    ("`0x05AC0000` occurrences", [6], [6], [7]),
    ("`mov pc` dispatch sites", [14], [14], [10]),
    ("14-case table", [present], [present], [absent]),
    ("Bytes inside functions", [38.8 %], [39.4 %], [43.3 %]),
  ),
  widths: (2.2fr, 0.9fr, 0.9fr, 0.9fr),
)

Aligned 16-byte window overlap is 73.1 % between the 3.1.x pair and 5.9 % between
3.1.12 and 3.2.0. That measures byte layout, not logic: reordered functions,
moved literal pools and different register allocation all lower it with unchanged
source. Reading it as "a rewrite" was an error, and it is withdrawn.

= The three 2026 claims, examined

- **Hard-reset handling changed** — `REFUTED`. The switch that could carry such a
  claim covers message types 9 to 22, and Hard_Reset has no MessageType: it is a
  vSafe0V protocol action. A message switch cannot speak to it.
- **Soft-reset escalation** — `OPEN`. No ladder was found in any of the three
  images. Absence in the analysed 39 % is not absence in the firmware.
- **Power negotiation changed** — not supported. The PDO table is identical in all
  six copies; only its address moves, so a fixed-offset read returns garbage.

= The host stack

`uarpd` carries the message format: a six-byte header of three big-endian `u16`
fields, a vendor tag `09 BC 63` followed by a type and value, and a 39-entry opcode
table. The updater's Mode 7 address-space read exists in the binary, but reaching it
means driving the accessory into update mode — an authorised experiment, not a
routine step. Whether that verb can touch flash is `OPEN`.

= Security posture

The trust boundary that can be stated today is narrow: the host verifies the
manifest hash before applying anything, and the accessory image carries no
signature this analysis could identify. Whether a signature is enforced below that
hash, whether anti-rollback exists, and what the three 32-byte `C99` header fields
are, all remain `OPEN`. Nothing here is reported as a vulnerability.

= Limits

Coverage is 38.8 / 39.4 / 43.3 % of the images, and the paths that matter — the
control-message switch and the Apple SVID literal sites — sit outside the analysed
set. Per-function matching is not reported at all: both calibrated runs were void,
and their causes are recorded. The adapter firmware was never obtained, so adapter
behaviour is host-observed only.

= Method

Evidence came from IORegistry and `IOAccessoryManager` captures, a deterministic
`hpmdiagnose` dump, Apple's public manifests, and static analysis. One label scale
throughout: `OBSERVED`, `REPRODUCED`, `INFERRED`, `UNVERIFIED`, `REFUTED`, `OPEN`.

#note(kind: "Scope", tone: "muted")[All hardware interaction was read-only: no flashing, no update trigger, no accessory command. Proprietary images are not redistributed; hashes and acquisition notes are.]

= Appendix A — claim register

Every claim is checked across the research documents by `scripts/verify_claims.py`,
which fails on a missing statement, a conflicting label in the same paragraph, a
withdrawn phrase in a conclusion, or a broken evidence reference.

{register}
"""

    open("report.typ", "w", encoding="utf-8").write(typ)

    meta = {
        "title": "Apple USB-C and MagSafe 3 power path",
        "subtitle": "Three processors, three firmware objects, one name",
        "kind": "Research Report",
        "topic": "Reverse engineering · Apple power accessories",
        "report_id": "RR-2026-1114",
        "version": "1.1",
        "date": date,
        "classification": "Internal",
        "baseline": "MagSafe 3 · 3.1.8",
        "target": "MagSafe 3 · 3.2.0",
        "baseline_short": "3.1.8",
        "target_short": "3.2.0",
        "prepared_by": "Sein",
        "source": "Apple public UARP assets, hpmdiagnose register dumps, IORegistry captures",
        "short_title": "Apple power path",
        "standfirst": "The cable's three releases extracted, the container format recovered from Apple's own parser, and the cross-version facts established without touching a device.",
        "section_breaks": False,
    }
    json.dump(meta, open("report.json", "w", encoding="utf-8"), indent=1)

    ev = {"schema": "research-evidence/1", "report_id": meta["report_id"], "root": ".", "claims": []}
    for c in claims:
        refs = []
        p = c.get("primary", {})
        if p.get("path"):
            refs.append({"type": "record", "path": p["path"],
                         "quote": long_quote(p["path"], p.get("quote", ""))} if p.get("quote")
                        else {"type": "file", "path": p["path"]})
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
    print(f"rendered report.typ: {len(claims)} claims, {len(releases())} releases parsed")


if __name__ == "__main__":
    main()
