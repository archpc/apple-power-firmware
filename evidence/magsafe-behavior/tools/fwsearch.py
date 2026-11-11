#!/usr/bin/env python3
"""Binary search helpers for flat ARM Thumb images at base 0."""
import struct, sys

def find_word(data, val, size=4):
    pat = struct.pack('<I', val) if size == 4 else struct.pack('<H', val)
    out, i = [], data.find(pat)
    while i != -1:
        out.append(i)
        i = data.find(pat, i + 1)
    return out

def find_all(data, pat):
    out, i = [], data.find(pat)
    while i != -1:
        out.append(i)
        i = data.find(pat, i + 1)
    return out

def hexdump(data, off, length, base=0x0):
    lines = []
    for r in range(0, length, 16):
        chunk = data[off + r: off + r + 16]
        if not chunk:
            break
        h = ' '.join(f'{b:02x}' for b in chunk)
        a = ' '.join(f'{b:02x}' for b in chunk[:8])
        b = ' '.join(f'{b:02x}' for b in chunk[8:])
        asc = ''.join(chr(c) if 32 <= c < 127 else '.' for c in chunk)
        lines.append(f'{base+off+r:08x}  {a:<23}  {b:<23}  |{asc}|')
    return '\n'.join(lines)

def cstring(data, off, maxlen=96):
    end = data.find(b'\x00', off)
    if end == -1 or end - off > maxlen:
        return None
    raw = data[off:end]
    if not raw or any(c < 32 or c > 126 for c in raw):
        return None
    return raw.decode('ascii')

def main():
    pass

if __name__ == '__main__':
    main()
