// Dump per-function mnemonic sequences from an already-analysed program.
// Read-only; run on the saved seeded project with -noanalysis.
// Usage: MnemSeqs.java <out.json>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class MnemSeqs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        PrintWriter w = new PrintWriter(new FileWriter(out));
        w.println("[");
        boolean first = true;
        for (Function f : fm.getFunctions(true)) {
            long size = 0;
            List<String> mn = new ArrayList<>();
            for (AddressRange rg : f.getBody().getAddressRanges()) {
                size += rg.getLength();
                Address a = rg.getMinAddress();
                while (a != null && a.compareTo(rg.getMaxAddress()) <= 0) {
                    Instruction ins = listing.getInstructionAt(a);
                    if (ins == null) { a = a.add(1); continue; }
                    mn.add(ins.getMnemonicString());
                    a = a.add(ins.getLength());
                }
            }
            if (!first) w.println(",");
            first = false;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < mn.size(); i++) {
                if (i > 0) sb.append(' ');
                sb.append(mn.get(i));
            }
            w.println("{\"addr\":\"0x" + Long.toHexString(f.getEntryPoint().getOffset())
                + "\",\"size\":" + size + ",\"n\":" + mn.size()
                + ",\"name\":\"" + f.getName().replace("\"", "") + "\""
                + ",\"mnems\":\"" + sb + "\"}");
        }
        w.println("]");
        w.close();
        println("MNEMS DONE functions=" + fm.getFunctionCount());
    }
}
