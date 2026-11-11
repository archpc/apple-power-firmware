# STATUS — state of the adapter-70w branch

As of 2026-11-11. Research branch only; not merged.

## Settled

- **Adapter identity** (OBSERVED): Apple A2743 70 W USB-C, ODM Salcomp,
  20.6 V × 3.4 A, host-visible `VID 0x05AC / PID 0x701C`, firmware string
  `"01030030"` (decomposition OPEN). Controller reported as Infineon CCG3PA2
  `CYPDC1185B2` from a single teardown source.
- **Register map** (OBSERVED bytes, INFERRED layout): `0x43` attached partner
  identity, `0x47` host controller identity, `0x49` cable SOP' identity,
  `0x30` source capabilities. `0x48` meaning OPEN; `0x4f` volatile.
- **Active RDO** `0x45854D53`: position 4, 3390/3390 mA, Capability Mismatch
  set, GiveBack clear. `PortControllerCapMismatch = 0` conflicts; OPEN.
- **Metadata provenance** (OBSERVED publisher, INFERRED transport):
  `AppleSmartBatteryManager` on `AppleSmartBattery` publishes `AdapterDetails`;
  per-port 4CC key reads. The adapter model is a CoreUARP literal.
- **Updater behaviour** (OBSERVED): macOS recognises `modelNumber=A2743`, checks
  for an asset, and gets `response: 43` every time. Update-capable, never
  update-delivered.
- **Distribution** (OBSERVED): no public asset in mesu or Pallas, no CDN path,
  no local cache.

## Blocked

- **No firmware image obtainable.** The only software read primitive (`CFUa`)
  is reachable only through `accessoryupdaterd`, which rejects clients without
  the Apple-private `com.apple.accessoryupdater.uarp` entitlement. Page 27
  reads work for the cable (6); the adapter class never queries it, so it is
  untested there.
- **Physical dump** requires opening a sealed mains adapter and a chip
  protection byte in OPEN state; PROTECTED erases on recovery, KILL is terminal.
  Prohibited and unsafe.
- **Supported-accessory table location** unconfirmed; `/var/db/accessoryupdater`
  unreadable without root.

## Live watcher

Cron `db05dacab515`, daily 09:00 America/New_York, no-agent, silent unless an
A2743 asset appears. Script `~/.hermes/scripts/a2743-asset-watch.sh`; log
`~/.hermes/cache/a2743-asset-watch.log`.

## Holdings

No proprietary firmware bytes were obtained. Nothing binary from Apple is in
this branch. If an image is ever acquired it stays local; only hashes and
provenance are committed.

## Resume here

1. `README.md` — findings and prior-session audit.
2. `REGISTERS.md` — register and RDO decode; `IDENTITY.md` — hardware.
3. `HOST.md` — provenance and updater; `DISTRIBUTION.md` — negative scope.
4. `DUMP-FEASIBILITY.md` — acquisition routes and exact blockers.
5. `OPEN.md` — ranked next questions.

Reproduce: `python3 adapter-70w/scripts/registers.py evidence/hpm-regs.json`
and `python3 scripts/verify_docs.py .`.
