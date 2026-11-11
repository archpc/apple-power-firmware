// Per-seed diagnosis on a program that has had DEFAULT analysis only (no seeding).
// Reports, for each seed address: listing unit type, containing function,
// inbound references, disassembly attempt and its outcome. No clearing, no forcing.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.Reference;
import java.io.*;
import java.util.*;

public class DiagSeeds extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        BufferedReader r = new BufferedReader(new FileReader(args[0]));
        PrintWriter out = new PrintWriter(new FileWriter(args[1]));
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        String line;
        while ((line = r.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            long a = Long.parseLong(line.replaceFirst("(?i)^0x", ""), 16);
            Address addr = toAddr(a);
            StringBuilder sb = new StringBuilder();
            sb.append("seed 0x" + Long.toHexString(a));
            CodeUnit cu = listing.getCodeUnitAt(addr);
            String unitDesc;
            if (cu == null) unitDesc = "none";
            else if (cu instanceof Instruction) unitDesc = "instruction:" + cu;
            else unitDesc = "data: len=" + cu.getLength();
            sb.append(" | unit=" + unitDesc);
            Function cf = fm.getFunctionContaining(addr);
            sb.append(" | inFunc=" + (cf == null ? "-" : cf.getName() + "@0x"
                + Long.toHexString(cf.getEntryPoint().getOffset())));
            Reference[] refs = getReferencesTo(addr);
            StringBuilder rs = new StringBuilder();
            int n = 0;
            for (Reference ref : refs) {
                if (n++ >= 4) { rs.append("..."); break; }
                rs.append("0x" + Long.toHexString(ref.getFromAddress().getOffset())
                    + "(" + ref.getReferenceType() + ") ");
            }
            sb.append(" | refsTo=" + (n == 0 ? "NONE" : rs));
            boolean ok = false;
            try {
                disassemble(addr);
                ok = getInstructionAt(addr) != null;
            } catch (Exception e) {
                sb.append(" | disasmEx=" + e.getMessage());
            }
            sb.append(" | disasm=" + (ok ? "OK:" + getInstructionAt(addr) : "FAILED"));
            out.println(sb);
        }
        out.close();
        r.close();
        println("DIAG DONE");
    }
}
