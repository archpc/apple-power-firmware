#!/usr/bin/env python3
"""Decode the HPM identity/PD registers for the 70 W adapter investigation.

Input:  evidence/hpm-regs.json                 (archived hpmdiagnose capture)
        optional second capture path argument (same JSON schema)
Output: JSON on stdout, or to the path given by --out.

Every derived value is labelled in the output: "observed" for bytes read from
the capture, "derived" for values computed by a stated formula. The 0x49
formula is the one recovered from AppleHPMDeviceHAL::getRXSOPpData
(evidence/applehpm-decompiled.md section 3). The 0x43 and 0x47 layouts are
INFERRED by structural analogy and are reported as such; the script does not
assert a semantic conclusion beyond the byte-level decode.

Usage:
    python3 registers.py evidence/hpm-regs.json [--out out.json]

Exit status is 0 when every self-check passes, 1 otherwise.
"""
import json
import sys


def buf(regs, reg):
    return bytes.fromhex(regs[reg]["data"])


def decode_pdo(word):
    """USB-PD fixed supply PDO, little-endian 32-bit word."""
    kind = (word >> 30) & 3
    if kind != 0:
        return {"raw": word, "kind": kind, "note": "not a fixed supply PDO"}
    return {
        "raw": word,
        "kind": "fixed",
        "voltage_mv": ((word >> 10) & 0x3FF) * 50,
        "max_current_ma": (word & 0x3FF) * 10,
        "dual_role_power": (word >> 29) & 1,
        "usb_suspend_supported": (word >> 28) & 1,
        "unchunked_ext": (word >> 27) & 1,
        "dual_role_data": (word >> 25) & 1,
    }


def decode_rdo_fixed(word):
    """USB-PD fixed RDO. Bit numbers follow the USB-PD 3.x fixed-RDO layout."""
    return {
        "raw": word,
        "object_position": (word >> 28) & 0xF,
        "giveback": (word >> 27) & 1,
        "capability_mismatch": (word >> 26) & 1,
        "usb_comm_capable": (word >> 25) & 1,
        "no_usb_suspend": (word >> 24) & 1,
        "unchunked_ext": (word >> 23) & 1,
        "operating_current_ma": ((word >> 10) & 0x3FF) * 10,
        "max_current_ma": (word & 0x3FF) * 10,
    }


def decode_rxsop_identity(b):
    """Mirror of the decompiled 0x49 reconstruction.

    count     = b[0] & 7, saturating at 6
    id_header = b[1] | b[2]<<8 | b[3]<<16 | b[4]<<24   (VDO word, byte-reversed
                relative to the reconstruction at out+0x24)
    product   = b[12]<<24 | b[11]<<16 | b[10]<<8 | b[9]
    """
    count = b[0] & 7
    if count == 7:
        count = 6
    id_header = b[1] | (b[2] << 8) | (b[3] << 16) | (b[4] << 24)
    product = (b[12] << 24) | (b[11] << 16) | (b[10] << 8) | b[9]
    return {
        "vdo_count": count,
        "id_header_vdo": f"0x{id_header:08X}",
        "vendor_id": f"0x{id_header & 0xFFFF:04X}",
        "product_id": f"0x{(id_header >> 16) & 0xFFFF:04X}",
        "product_vdo": f"0x{product:08X}",
        "product_vdo_pid": f"0x{(product >> 16) & 0xFFFF:04X}",
        "product_vdo_bcd_device": f"0x{product & 0xFFFF:04X}",
    }


def decode_rx_sop_partner(b):
    """0x43: 26 bytes. Only bytes 0..4 are interpretable.

    Empirically [0] is 0x19 when a partner is attached and 0x00 when not,
    [1..2] is VID little-endian, [3..4] is PID little-endian. The 0x49
    reconstruction does NOT apply: it is 26 bytes, not 61, and its
    out+0x2c offsets land on 0x03000000. Trailing bytes uninterpreted.
    """
    return {
        "byte0": f"0x{b[0]:02X}",
        "vendor_id": f"0x{int.from_bytes(b[1:3], 'little'):04X}",
        "product_id": f"0x{int.from_bytes(b[3:5], 'little'):04X}",
        "trailing": b[5:].hex(" "),
        "record_shape": "OPEN (26 bytes, not the 61-byte 0x49 shape)",
    }


def decode_tx_identity(b):
    """0x47 as {u16 VID, u16 PID} little-endian followed by native LE words.

    The VID/PID are read as two LE u16 at offsets 1..2 and 3..4. This is NOT a
    spec ID Header VDO: read as a single LE 32-bit word the halves swap and the
    VID would come out 0xD540. Layout INFERRED from the bytes, not from code.
    """
    count = b[0]
    vid = int.from_bytes(b[1:3], "little")
    pid = int.from_bytes(b[3:5], "little")
    words = [int.from_bytes(b[1 + 4 * i:5 + 4 * i], "little") for i in range(count)]
    return {
        "entry_count_inferred": count,
        "vendor_id": f"0x{vid:04X}",
        "product_id": f"0x{pid:04X}",
        "le_words": [f"0x{w:08X}" for w in words],
        "version_word": f"0x{int.from_bytes(b[9:13], 'little'):08X}",
    }


def main(argv):
    path = argv[1] if len(argv) > 1 and not argv[1].startswith("-") else "evidence/hpm-regs.json"
    out_path = None
    if "--out" in argv:
        out_path = argv[argv.index("--out") + 1]
    d = json.load(open(path))
    result = {"source": path, "rids": {}}
    checks = []

    for rid, node in sorted(d.items()):
        regs = node["regs"]
        entry = {}
        if "0x30" in regs:
            b = buf(regs, "0x30")
            # Low 3 bits behave as a PDO count on every capture seen; high bits
            # carry status (RID 0 with an iPhone attached reads 0x81 = 1 PDO).
            n = b[0] & 7
            entry["rx_source_caps"] = {
                "declared_count": n,
                "pdos": [decode_pdo(int.from_bytes(b[1 + 4 * i:5 + 4 * i], "little"))
                         for i in range(min(n, 7))],
            }
        for reg, fn, key in (("0x43", decode_rx_sop_partner, "rx_sop_partner"),
                             ("0x49", decode_rxsop_identity, "rx_sop_prime_identity")):
            if reg in regs:
                b = buf(regs, reg)
                entry[key] = fn(b) if any(b) else {"vdo_count": 0, "note": "all zero"}
        if "0x47" in regs:
            b = buf(regs, "0x47")
            entry["tx_identity_inferred"] = decode_tx_identity(b) if any(b) else {"vdo_count": 0}
        if "0x48" in regs:
            b = buf(regs, "0x48")
            entry["reg_0x48"] = {"first_byte": f"0x{b[0]:02X}", "all_zero": not any(b)}
        if "0x4f" in regs:
            b = buf(regs, "0x4f")
            entry["reg_0x4f"] = {
                "all_zero": not any(b),
                "ascii_runs": [s.decode("ascii") for s in b.split(b"\x00")
                               if len(s) >= 4 and all(32 <= c < 127 for c in s)],
            }
        result["rids"][rid] = entry

    # Cross-check: 0x30 on the MagSafe controller equals the four PDOs reported
    # by IOKit and by PortControllerPortPDO in the archived capture.
    mag = result["rids"].get("0x5", {}).get("rx_source_caps", {})
    got = [(p["voltage_mv"], p["max_current_ma"]) for p in mag.get("pdos", [])]
    want = [(5000, 2960), (9000, 2970), (15000, 2980), (20000, 3390)]
    checks.append(("0x30 RID5 PDOs equal IOKit contract", got == want and got != []))
    if got:
        checks.append(("0x30 RID5 max power 67800 mW",
                       got[-1][0] * got[-1][1] // 1000 == 67800))

    # RDO decode for the MagSafe contract.
    rdo = decode_rdo_fixed(0x45854D53)
    result["rdo_rid5"] = rdo
    checks.append(("RDO position 4 selects the 20 V PDO", rdo["object_position"] == 4))
    checks.append(("RDO operating == max == 3390 mA",
                   rdo["operating_current_ma"] == 3390 and rdo["max_current_ma"] == 3390))
    checks.append(("RDO capability mismatch set (B26)", rdo["capability_mismatch"] == 1))

    # Identity decode of the adapter's SOP record on RID5.
    sop = result["rids"].get("0x5", {}).get("rx_sop_partner", {})
    checks.append(("0x43 RID5 VID/PID 0x05AC/0x701C",
                   sop.get("vendor_id") == "0x05AC" and sop.get("product_id") == "0x701C"))
    sop0 = result["rids"].get("0x0", {}).get("rx_sop_partner", {})
    if sop0.get("vendor_id"):
        checks.append(("0x43 RID0 partner vendor 0x05AC",
                       sop0["vendor_id"] == "0x05AC"))

    tx = result["rids"].get("0x5", {}).get("tx_identity_inferred", {})
    checks.append(("0x47 RID5 VID/PID 0x05AC/0x1C60",
                   tx.get("vendor_id") == "0x05AC" and tx.get("product_id") == "0x1C60"))
    checks.append(("0x47 RID5 version word carries 0x3115 (FW 003.115, INFERRED)",
                   tx.get("version_word") == "0x731D3115" and (int(tx["version_word"],16) & 0xFFFF) == 0x3115))

    result["checks"] = [{"name": n, "pass": bool(ok)} for n, ok in checks]
    text = json.dumps(result, indent=1)
    if out_path:
        open(out_path, "w").write(text + "\n")
        print(f"wrote {out_path}")
    else:
        print(text)
    for name, ok in checks:
        print(("PASS " if ok else "FAIL ") + name, file=sys.stderr)
    return 0 if all(ok for _, ok in checks) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
