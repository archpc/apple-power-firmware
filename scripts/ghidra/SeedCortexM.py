# Seeded Cortex-M re-analysis of flat MagSafe A2363 images (Jython/Ghidra script).
# args: seedsCsv outJson decompDir
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
seeds_csv, out_json, out_dir = args[0], args[1], args[2]
log_lines = []

seeds = []
for line in open(seeds_csv):
    line = line.strip()
    if line and not line.startswith('#'):
        seeds.append(int(line.split(',')[0], 16))

fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
for a in seeds:
    addr = toAddr(a)
    pre = fm.getFunctionContaining(addr)
    disassemble(addr)
    ins = getInstructionAt(addr)
    f = getFunctionAt(addr)
    if f is None:
        f = createFunction(addr, None)
    log_lines.append("seed %x -> %s | instr=%s | preexisting=%s" % (
        a, f.getName() if f else "FAILED",
        "yes" if ins is not None else "NO-CODE",
        pre.getName() if pre is not None else "-"))
analyzeAll(monitor)

if not os.path.isdir(out_dir):
    os.makedirs(out_dir)
out = open(out_json, 'w')
out.write("[\n")
first = True
funcs = list(fm.getFunctions(True))
for f in funcs:
    if not first:
        out.write(",\n")
    first = False
    size = sum(r.getLength() for r in f.getBody().getAddressRanges())
    out.write('{"addr":"0x%x","size":%d,"name":"%s"}' % (
        f.getEntryPoint().getOffset(), size, f.getName().replace('"', '')))
out.write("\n]\n")
out.close()

di = DecompInterface()
di.openProgram(currentProgram)
idx = open(os.path.join(out_dir, "decompile-index.json"), 'w')
idx.write("[\n")
first = True
for f in funcs:
    res = di.decompileFunction(f, 60, monitor)
    if res is not None and res.decompileCompleted():
        pseudo = res.getDecompiledFunction().getC()
    else:
        pseudo = "// DECOMP FAILED"
    name = "f_%x" % f.getEntryPoint().getOffset()
    pf = open(os.path.join(out_dir, name + ".c"), 'w')
    pf.write(pseudo)
    pf.close()
    if not first:
        idx.write(",\n")
    first = False
    size = sum(r.getLength() for r in f.getBody().getAddressRanges())
    idx.write('{"addr":"0x%x","size":%d}' % (f.getEntryPoint().getOffset(), size))
idx.write("\n]\n")
idx.close()
di.dispose()
open(out_json + ".log", 'w').write("\n".join(log_lines) + "\n")
print("DONE functions=%d" % fm.getFunctionCount())
