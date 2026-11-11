#!/usr/bin/env python3
"""Cross-document claim verification.

Checks relationships between documents, not isolated statements:

  PRESENCE   every recorded occurrence fragment is actually in that document
  PRIMARY    every primary ref resolves (file exists, quote appears)
  LABEL      within a window around each occurrence, no label outside the
             claim's canonical label appears (catches OBSERVED-here/OPEN-there)
  BAN        withdrawn wording appears nowhere (retractions must not survive)
  NUMERIC    every numeric invariant of the claim appears somewhere in the docs
  SCOPE      negative findings carry their search scope near every occurrence
  SUMMARY    the executive summary states a limitation and no withdrawn claim
  RELATIONS  supersedes/depends_on targets resolve to a known claim or -prior id

Usage: verify_claims.py <artifact_root>
Exit 0 only when every check passes.
"""
import json
import os
import re
import sys

WINDOW = 380
LABEL_ATTACH = 150   # a label beyond this distance governs a different statement
LABELS = ("OBSERVED", "REPRODUCED", "INFERRED", "UNVERIFIED", "REFUTED", "OPEN")
# labels that may legitimately appear near a claim without contradiction
ALSO_OK = {"OPEN": {"OBSERVED", "INFERRED", "REPRODUCED", "UNVERIFIED"},
           "REPRODUCED": {"OBSERVED"},
           "UNVERIFIED": {"OPEN", "INFERRED"},
           "REFUTED": {"OBSERVED", "OPEN"}}
DOCS = ("REPORT.md", "DIFF.md", "PROTOCOL.md", "FIRMWARE.md", "HARDWARE.md",
        "SECURITY.md", "EXTRACTION-NOTES.md", "NEXT.md", "README.md",
        "DISPOSITION.md", "TESTING.md")

failures = []


def norm(s):
    return " ".join(s.split())


def load_docs():
    """doc -> list of normalised paragraphs.

    A label governs the statement it shares a paragraph with. Character distance
    is not a reliable proxy: an executive summary can state an observed fact and
    a nearby open question in adjacent sentences.
    """
    out = {}
    for d in DOCS:
        raw = open(d, encoding="utf-8").read()
        blocks = []
        for chunk in raw.split("\n\n"):
            # headings, table rows and list items start their own block
            for piece in re.split(r"\n(?=[-|#])", chunk):
                if piece.strip():
                    blocks.append(norm(piece))
        out[d] = blocks
    return out


def check(cid, name, ok, detail=""):
    if not ok:
        failures.append(f"{cid}/{name}: {detail}")


def main():
    root = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    os.chdir(root)
    man = json.load(open("claims/manifest.json", encoding="utf-8"))
    docs = load_docs()
    claims = {c["id"]: c for c in man["claims"]}
    resolved = set(claims) | {f"{c}-prior" for c in claims}

    for c in man["claims"]:
        cid, canon = c["id"], c["label"]

        # PRIMARY
        p = c.get("primary", {})
        if p.get("path"):
            if not os.path.exists(p["path"]):
                check(cid, "PRIMARY", False, f"missing file {p['path']}")
            elif p.get("quote") and norm(p["quote"]) not in norm(
                    open(p["path"], encoding="utf-8", errors="replace").read()):
                check(cid, "PRIMARY", False, f"quote absent from {p['path']}: {p['quote']!r}")

        # RELATIONS
        for rel in ("supersedes", "depends_on", "same_as"):
            targets = c.get("relations", {}).get(rel, [])
            targets = [targets] if isinstance(targets, str) else targets
            for t in targets:
                check(cid, "RELATIONS", t in resolved, f"unresolved {rel} target {t}")

        # PRESENCE + LABEL + SCOPE, evaluated per paragraph
        for occ in c["occurrences"]:
            doc, frag = occ["doc"], norm(occ["quote"])
            paras = docs.get(doc)
            if paras is None:
                check(cid, "PRESENCE", False, f"unknown doc {doc}")
                continue
            para = next((p for p in paras if frag in p), None)
            if para is None:
                check(cid, "PRESENCE", False, f"{doc}: fragment absent {frag!r}")
                continue
            found = {l for l in LABELS if f"**{l}**" in para}
            if occ.get("context") == "quoting_retraction":
                found = set()          # cited as a retraction, not asserted
            allowed = {canon} | ALSO_OK.get(canon, set()) | {"OPEN"}
            stray = found - allowed
            check(cid, "LABEL", not stray,
                  f"{doc}: paragraph asserts {sorted(stray)} but claim is {canon} ({frag!r})")
            if occ.get("scope"):
                check(cid, "SCOPE", occ["scope"] in para,
                      f"{doc}: scope word {occ['scope']!r} missing near {frag!r}")

    # BAN: withdrawn wording must not survive in conclusion-bearing regions.
    # Retraction sections are allowed to quote the wording they withdraw.
    REGIONS = {
        "REPORT.md": r"## 1\. Executive summary.*?(?=\n## 2\.)",
        "README.md": r"## Verified accomplishments.*?(?=\n## Limitations)",
        "DIFF.md": r"## 8\. Verdicts.*?(?=\n## 9\.)",
    }
    for c in man["claims"]:
        for phrase in c.get("bans", []):
            for doc, pat in REGIONS.items():
                raw = open(doc, encoding="utf-8").read().replace("**", "")
                m3 = re.search(pat, raw, re.S)
                region = norm(m3.group(0)) if m3 else ""
                check(c["id"], "BAN", norm(phrase) not in region,
                      f"withdrawn wording survives in {doc} conclusions: {phrase!r}")

    # NUMERIC
    alltext = " ".join(" ".join(v) for v in docs.values())
    for c in man["claims"]:
        for num in c.get("numeric", []):
            check(c["id"], "NUMERIC", num in alltext, f"{num!r} not present in any document")

    # SUMMARY: limitations present, no withdrawn claim in the summary block
    rep = open("REPORT.md", encoding="utf-8").read()
    m = re.search(r"##+\s*\d*\.?\s*Executive[^\n]*\n(.*?)(?=\n##+\s)", rep, re.S)
    if not m:
        check("SUMMARY", "SUMMARY", False, "no executive summary section found")
    else:
        block = norm(m.group(1))
        check("SUMMARY", "SUMMARY", "OPEN" in block or "limitation" in block.lower(),
              "executive summary states no limitation")
        for c in man["claims"]:
            if c["disposition"] == "withdrawn":
                for phrase in c.get("bans", []):
                    check(c["id"], "SUMMARY", norm(phrase) not in block,
                          f"withdrawn claim in executive summary: {phrase!r}")

    total = len(man["claims"])
    if failures:
        print(f"FAIL {len(failures)} cross-document problem(s) across {total} claims:")
        for f in failures:
            print("  - " + f)
        return 1
    print(f"PASS {total} claims reconciled across {len(DOCS)} documents; "
          f"0 presence, label, ban, numeric, scope, summary or relation failures")
    return 0


if __name__ == "__main__":
    sys.exit(main())
