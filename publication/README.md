# publication/

One copy of each build, no duplicates.

```
current/apple-power-firmware.pdf   the shipped build (9 pages)
prior/claim-register-6pp.pdf       the superseded first publication (6 pages)
```

`current/` holds exactly one file: the PDF that best represents this research
today. When it is replaced, the old file moves to `prior/` under a name that says
what it was and how big it was — never left beside the new one as
`apple-power-firmware-v2.pdf`, and never overwritten in place.

`prior/` exists because the first publication passed every check and was still a
worse report. The comparison, the sources and the editorial decision record live in
`../fixtures/content-vs-compliance/`, which reads both PDFs by relative path and
keeps no copy of its own.

Rebuild (from the repository root, typesetting sources are `report.typ` /
`report.json`):

```bash
python3 scripts/build_report.py .
python3 ~/.hermes/skills/research/research-pdf/scripts/build.py \
  --content report.typ --meta report.json \
  --out publication/current/apple-power-firmware.pdf --inspect
```

Generation identifiers: current `1848b3a363df46de`, prior `552a3e6f895d97f0`. The
evidence sidecars (`*.build.json`, `*.evidence.json`) are generated at build time
and are gitignored; the PDF carries its own provenance in the git history.

Proprietary Apple firmware is not published here. See `../firmware/MANIFEST.txt`
for what was acquired, from where, and with which hash.
