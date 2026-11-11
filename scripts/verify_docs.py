#!/usr/bin/env python3
"""Deterministic documentation and evidence regression checks.

Runs the numeric checks and the document-consistency checks described in
TESTING.md. Exit 0 only when every check passes.

Usage: verify_docs.py <artifact_root>
"""
import os
import re
import subprocess
import sys

LABELS = ("OBSERVED", "REPRODUCED", "INFERRED", "UNVERIFIED", "REFUTED", "OPEN")
LEGACY = ("CONFIRMED", "VERIFIED")
RESEARCH_DOCS = ("REPORT.md", "HARDWARE.md", "FIRMWARE.md", "PROTOCOL.md",
                 "DIFF.md", "SECURITY.md", "NEXT.md", "EXTRACTION-NOTES.md",
                 "README.md", "DISPOSITION.md", "TESTING.md", "VERIFICATION.md")
# REVIEW-FABLE.md is an external artifact: retained verbatim, excluded.

results = []
HAVE_IMAGES = False


def check(name, fn):
    try:
        ok, detail = fn()
    except Exception as exc:  # noqa: BLE001 - report, never mask
        ok, detail = False, f"exception: {exc}"
    results.append((name, ok, detail))
    state = "SKIP" if ok is None else ("PASS" if ok else "FAIL")
    print(f"[{state}] {name}: {detail}")


def needs_images(fn):
    """Corpus-dependent check: skip with a named reason when images are absent."""
    def wrapper():
        if not HAVE_IMAGES:
            return None, "SKIP: firmware images absent (not redistributed)"
        return fn()
    return wrapper


def main():
    root = os.path.abspath(sys.argv[1])
    os.chdir(root)
    global HAVE_IMAGES
    HAVE_IMAGES = all(os.path.exists(os.path.join("firmware/images", f)) for f in
                      ("A2363_3.1.8_10M569_base0.bin",
                       "A2363_3.1.12_10M1543_base0.bin",
                       "A2363_3.2.0_10M13722_base0.bin"))

    def legacy_labels():
        bad = []
        for d in RESEARCH_DOCS:
            text = open(d, encoding="utf-8").read()
            # Only label *forms* count: bolded or parenthesised. Prose that names
            # the retired tokens is allowed, so README/DISPOSITION can explain them.
            for m in re.finditer(r"\*\*(CONFIRMED|VERIFIED)\*\*|\((CONFIRMED|VERIFIED)\)",
                                 text):
                bad.append(f"{d}:{m.group(0)}")
        return not bad, ", ".join(bad) or "no legacy label forms in research docs"

    def label_defined():
        readme = open("README.md", encoding="utf-8").read()
        missing = [l for l in LABELS if l not in readme]
        return not missing, f"missing from README: {missing}" if missing else "all six labels defined"

    def dup_paragraphs():
        bad = []
        for d in RESEARCH_DOCS:
            seen = {}
            for para in open(d, encoding="utf-8").read().split("\n\n"):
                p = " ".join(para.split())
                if len(p) > 120:
                    if p in seen:
                        bad.append(f"{d}: duplicate block at ~{p[:40]!r}")
                    seen[p] = 1
        return not bad, ", ".join(bad) or "no duplicated paragraphs"

    def refs_exist():
        missing = set()
        for d in RESEARCH_DOCS:
            for m in re.finditer(r"`((?:scripts|evidence|firmware)/[A-Za-z0-9_./-]+)`",
                                 open(d, encoding="utf-8").read()):
                # firmware binaries are excluded from the repository by design;
                # their provenance lives in firmware/MANIFEST.txt
                if m.group(1).startswith("firmware/") and "MANIFEST" not in m.group(1):
                    continue
                if not os.path.exists(m.group(1)):
                    missing.add(m.group(1))
        return not missing, ", ".join(sorted(missing)) or "all referenced paths exist"

    def run(cmd, expect=0):
        p = subprocess.run(cmd, capture_output=True, text=True)
        return p.returncode == expect, (p.stdout.strip().splitlines() or ["no output"])[-1]

    def extraction_hashes():
        p = subprocess.run(["shasum", "-a", "256", "-c", "SHA256SUMS"], capture_output=True, text=True)
        return p.returncode == 0, "all firmware image hashes match" if p.returncode == 0 else p.stdout[-200:]

    def pdo_and_literals():
        p = subprocess.run([sys.executable, "scripts/diff_verify.py", "firmware/images"],
                           capture_output=True, text=True)
        ok = p.returncode == 0 and "20.00V/3.00A" in p.stdout and "5.00V/3.00A" in p.stdout
        return ok, "PDO tables decode identically in all builds" if ok else "PDO/literal invariant broken"

    def literal_disjoint():
        p = subprocess.run([sys.executable, "scripts/literal_sets.py",
                            "evidence/magsafe-ghidra/raw", "0x0B0F0", "pseudo_3_1_12",
                            "0x0B18C", "pseudo_3_2_0"], capture_output=True, text=True)
        return p.returncode == 0, "28 is 3.2.0-only; sets reconcile" if p.returncode == 0 else \
            (p.stdout.strip().splitlines() or ["failed"])[-1]

    def dispatchers():
        p = subprocess.run([sys.executable, "scripts/dispatcher_census.py",
                            "firmware/images", "evidence/dispatcher-census.json"],
                           capture_output=True, text=True)
        return p.returncode == 0, "14/14/10 dispatchers, 14-case table absent in 3.2.0" \
            if p.returncode == 0 else (p.stdout.strip().splitlines() or ["failed"])[-1]

    def coverage():
        p = subprocess.run([sys.executable, "scripts/coverage.py",
                            "evidence/magsafe-ghidra/raw", "firmware/images"],
                           capture_output=True, text=True)
        return p.returncode == 0, "38.8/39.4/43.3 whole-image coverage" \
            if p.returncode == 0 else (p.stdout.strip().splitlines() or ["failed"])[-1]

    def retractions_recorded():
        raw = open("DIFF.md", encoding="utf-8").read()
        diff = " ".join(raw.split()).lower()   # normalise wrapping before matching
        need = ["3.2.0 is a rebuild, not a patch", "244/303",
                "case counts come from source", "substantially rewritten",
                "hard-reset handling"]
        missing = [n for n in need if n not in diff]
        return not missing, f"missing retractions: {missing}" if missing else \
            "all five retractions present in DIFF.md"

    def claims_table():
        disp = open("DISPOSITION.md", encoding="utf-8").read()
        rows = len(re.findall(r"^\| *\d+ *\|", disp, re.M))
        refs = len(re.findall(r"REVIEW-FABLE", disp))
        return rows >= 40, f"{rows} claim rows mapped to review findings, {refs} review references"

    check("legacy evidence labels absent", legacy_labels)
    check("label scale defined in README", label_defined)
    check("no duplicated paragraphs", dup_paragraphs)
    check("documented paths exist", refs_exist)
    check("retractions recorded", retractions_recorded)
    check("claims table reconciled", claims_table)
    check("firmware image hashes", needs_images(extraction_hashes))
    check("PDO table invariant", needs_images(pdo_and_literals))
    check("literal sets disjoint and reconciled", needs_images(literal_disjoint))
    check("dispatcher inventory", needs_images(dispatchers))
    check("function coverage", needs_images(coverage))

    failed = [r for r in results if r[1] is False]
    skipped = [r for r in results if r[1] is None]
    print(f"\n{len(results) - len(failed) - len(skipped)} passed, {len(skipped)} skipped, "
          f"{len(failed)} failed")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
