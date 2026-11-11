#!/usr/bin/env python3
"""Linear-sweep Thumb disassembly, collecting PC-relative / movw-movt address references."""
import sys, struct
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_LITTLE_ENDIAN
from capstone.arm import ARM_OP_IMM, ARM_OP_MEM, ARM_REG_PC

def disasm(data, base=0):
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_LITTLE_ENDIAN)
    md.detail = True
    return md, md.disasm(data, base)

def collect_refs(data, lo, hi, base=0):
    """Find instructions whose immediate / literal target falls in [lo,hi)."""
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_LITTLE_ENDIAN)
    md.detail = True
    hits = []
    for ins in md.disasm(data, base):
        for op in ins.operands:
            if op.type == ARM_OP_IMM and lo <= op.imm < hi:
                hits.append((ins.address, ins.mnemonic, ins.op_str, op.imm))
            elif op.type == ARM_OP_MEM and op.mem.base == ARM_REG_PC:
                # ldr rX, [pc, #imm]  -> literal at align(addr+4,4)+imm
                lit = (ins.address + 4) & ~3
                lit += op.mem.disp
                if 0 <= lit <= len(data) - 4:
                    val = struct.unpack('<I', data[lit:lit+4])[0]
                    if lo <= val < hi:
                        hits.append((ins.address, ins.mnemonic, ins.op_str + f'  ; [0x{lit:x}]=0x{val:x}', val))
    return hits
