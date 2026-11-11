#!/usr/bin/env python3
"""Full linear-sweep Thumb disassembly of a flat image, with literal-pool
annotations resolved (ldr rX,[pc,#imm]) and heuristic 'this word looks like a
string pointer' comments. Writes text to stdout for grepping."""
import sys, struct
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_LITTLE_ENDIAN
from capstone.arm import ARM_OP_MEM, ARM_REG_PC

def cstr(d, off, maxlen=120):
    if off < 0 or off >= len(d):
        return None
    end = d.find(b'\x00', off)
    if end == -1 or end - off > maxlen or end == off:
        return None
    raw = d[off:end]
    if any(c < 32 or c > 126 for c in raw):
        return None
    return raw.decode('ascii')

def main(path):
    d = open(path, 'rb').read()
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_LITTLE_ENDIAN)
    md.detail = True
    md.skipdata = True
    md.skipdata_setup = ("db", None, None)
    out = []
    for ins in md.disasm(d, 0):
        note = ''
        if ins.id == 0:  # skipdata pseudo-insn
            out.append(f'{ins.address:06x}  {ins.bytes.hex():<10} db       {d[ins.address]:02x}')
            continue
        for op in ins.operands:
            if op.type == ARM_OP_MEM and op.mem.base == ARM_REG_PC:
                lit = ((ins.address + 4) & ~3) + op.mem.disp
                if 0 <= lit <= len(d) - 4:
                    val = struct.unpack('<I', d[lit:lit+4])[0]
                    s = cstr(d, val)
                    note += f'   ; [0x{lit:x}]=0x{val:08x}'
                    if s:
                        note += f' "{s}"'
        out.append(f'{ins.address:06x}  {ins.bytes.hex():<10} {ins.mnemonic:<8} {ins.op_str}{note}')
    sys.stdout.write('\n'.join(out) + '\n')

if __name__ == '__main__':
    main(sys.argv[1])
