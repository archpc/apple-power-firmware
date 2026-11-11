// Seeded Cortex-M re-analysis of flat MagSafe A2363 images.
// Supported headless path: analyzeHeadless <projDir> <proj> -import <bin>
//   -processor ARM:LE:32:Cortex -cspec default
//   -scriptPath scripts/ghidra -postScript SeedCortexM.java <seedsCsv> <outJson> <outDir>
// seedsCsv: one hex address per line. Addresses are FILE OFFSETS (base-0 import);
// they are not asserted to be runtime addresses.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class SeedCortexM extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String seedsCsv = args[0], outJson = args[1], outDir = args[2];
        PrintWriter log = new PrintWriter(new FileWriter(outJson + ".log"));

        List<Long> seeds = new ArrayList<>();
        Set<Long> clearSet = new HashSet<>();
        Map<Long, Long> expLenMap = new HashMap<>();
        Map<Long, String> expTypeMap = new HashMap<>();
        BufferedReader r = new BufferedReader(new FileReader(seedsCsv));
        for (String line; (line = r.readLine()) != null; ) {
            line = line.trim(); if (line.isEmpty() || line.startsWith("#")) continue;
            String[] parts = line.split(",");
            long a = Long.parseLong(parts[0].replaceFirst("(?i)^0x", ""), 16);
            seeds.add(a);
            if (line.toLowerCase().contains(",clear")) {
                clearSet.add(a);
                expLenMap.put(a, Long.parseLong(parts[2]));
                expTypeMap.put(a, parts[3]);
            }
        }
        r.close();

        FunctionManager fm = currentProgram.getFunctionManager();
        for (long a : seeds) {
            Address addr = toAddr(a);
            Function pre = fm.getFunctionContaining(addr);
            disassemble(addr);
            if (getInstructionAt(addr) == null && clearSet.contains(a)) {
                // Precise clear, gated on agreement with the recorded diagnosis:
                // unit start must equal the seed, and length/type must match the
                // expected values carried in the CSV. Any mismatch aborts the clear.
                CodeUnit cu = currentProgram.getListing().getCodeUnitAt(addr);
                Long expLen = expLenMap.get(a);
                String expType = expTypeMap.get(a);
                String before = (cu == null) ? "none" : cu.toString();
                boolean ok = cu != null
                    && cu.getAddress().getOffset() == a
                    && expLen != null && cu.getLength() == expLen
                    && expType != null && expType.equals(cu instanceof Instruction ? "instruction" : "data");
                if (!ok) {
                    log.println("  clear ABORTED for 0x" + Long.toHexString(a)
                        + " | before=" + before + " | expected len=" + expLen + " type=" + expType);
                } else {
                    log.println("  clear before: 0x" + Long.toHexString(a) + " " + before);
                    clearListing(addr, addr.add(cu.getLength() - 1));
                    disassemble(addr);
                    Instruction ni = getInstructionAt(addr);
                    log.println("  clear after : " + (ni != null ? ni.toString() : "STILL FAILED"));
                }
            }
            boolean hasIns = getInstructionAt(addr) != null;
            Function f = getFunctionAt(addr);
            if (f == null) f = createFunction(addr, null);
            log.println("seed 0x" + Long.toHexString(a) + " -> "
                + (f != null ? f.getName() : "FAILED")
                + " | instr=" + (hasIns ? "yes" : "NO-CODE")
                + " | preexisting=" + (pre != null ? pre.getName() : "-"));
        }
        analyzeAll(currentProgram);

        new File(outDir).mkdirs();
        List<Function> funcs = new ArrayList<>();
        for (Function f : fm.getFunctions(true)) funcs.add(f);

        PrintWriter out = new PrintWriter(new FileWriter(outJson));
        out.println("[");
        boolean first = true;
        for (Function f : funcs) {
            if (!first) out.println(",");
            first = false;
            long size = 0;
            for (AddressRange rg : f.getBody().getAddressRanges()) size += rg.getLength();
            out.println("{\"addr\":\"0x" + Long.toHexString(f.getEntryPoint().getOffset())
                + "\",\"size\":" + size
                + ",\"name\":\"" + f.getName().replace("\"","") + "\"}");
        }
        out.println("]");
        out.close();

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        PrintWriter idx = new PrintWriter(new FileWriter(outDir + "/decompile-index.json"));
        idx.println("[");
        first = true;
        for (Function f : funcs) {
            DecompileResults res = di.decompileFunction(f, 60, monitor);
            String pseudo = (res != null && res.decompileCompleted())
                ? res.getDecompiledFunction().getC() : "// DECOMP FAILED";
            String name = "f_" + Long.toHexString(f.getEntryPoint().getOffset());
            PrintWriter pf = new PrintWriter(new FileWriter(outDir + "/" + name + ".c"));
            pf.print(pseudo); pf.close();
            if (!first) idx.println(",");
            first = false;
            long size = 0;
            for (AddressRange rg : f.getBody().getAddressRanges()) size += rg.getLength();
            idx.println("{\"addr\":\"0x" + Long.toHexString(f.getEntryPoint().getOffset())
                + "\",\"size\":" + size + "}");
        }
        idx.println("]");
        idx.close();
        di.dispose();
        log.close();
        println("DONE functions=" + fm.getFunctionCount());
    }
}
