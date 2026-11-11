#!/usr/bin/env python3
"""Compare two publications that both passed the gate, and refuse to judge them.

This fixture exists because technical compliance was not enough. The six-page
document passes every structural check the skill enforces: text layer, no blank
pages, evidence resolvable, layout gate clean, deterministic output. It is still a
worse report than the nine-page one, and no validator in this skill can say so.

The script therefore reports measurements and stops. It must never be extended to
emit a verdict: a passing "quality score" would be exactly the false comfort this
fixture was created to prevent.

Usage: compare.py [fixture_dir]
Exit 0 when both files open and the recorded shapes match; that is a statement
about validity, not about quality.
"""
import json
import os
import re
import subprocess
import sys

SWIFT_PAGES = """import PDFKit
import Foundation
let u = URL(fileURLWithPath: ProcessInfo.processInfo.environment["FIXTURE_PDF"]!)
guard let d = PDFDocument(url: u) else { print("0 0"); exit(1) }
var chars = 0
for i in 0..<d.pageCount { chars += (d.page(at: i)?.string ?? "").count }
print("\\(d.pageCount) \\(chars)")"""


def measure(pdf):
    env = dict(os.environ, FIXTURE_PDF=pdf)
    p = subprocess.run(["swift", "-e", SWIFT_PAGES], capture_output=True, text=True, env=env)
    if p.returncode != 0:
        return None, None
    pages, chars = p.stdout.split()
    return int(pages), int(chars)


def structure(typ):
    src = open(typ, encoding="utf-8").read()
    return {
        "sections": len(re.findall(r"^= ", src, re.M)),
        "subsections": len(re.findall(r"^== ", src, re.M)),
        "tables": src.count("#data-table("),
        "claim_markers": len(re.findall(r"^// claim:", src, re.M)),
        "words": len(re.findall(r"\b[\w'-]+\b", re.sub(r"#[a-z-]+\(|\"|\]|\[", " ", src))),
    }


def main():
    d = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else os.path.dirname(__file__))
    rows, ok = [], True
    for name, label, expect_pages in (
            ("claim-register-6pp", "six-page claim register", 6),
            ("research-narrative-9pp", "nine-page research narrative", 9)):
        pdf = os.path.join(d, name + ".pdf")
        pages, chars = measure(pdf)
        st = structure(os.path.join(d, name + ".typ"))
        rows.append((label, pages, chars, st))
        if pages != expect_pages:
            ok = False
            print(f"MISMATCH {name}: {pages} pages, expected {expect_pages}")

    print(f"\n{'document':32s} {'pages':>5s} {'chars':>7s} {'sects':>6s} {'tables':>7s} {'claims':>7s}")
    for label, pages, chars, st in rows:
        print(f"{label:32s} {pages:>5d} {chars:>7d} {st['sections']:>6d} "
              f"{st['tables']:>7d} {st['claim_markers']:>7d}")

    print("\nBoth passed the publication gate. The gate measured whether claims were")
    print("anchored and layout was sound; it had nothing to say about whether the")
    print("document was worth reading. That gap is the fixture.")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
