// Dump instructions in given [start,end) ranges for a flat base-0 ARM Cortex-M image.
// Read-only. Usage: DumpRange.java <out.txt> <startHex> <endHex> [<startHex> <endHex> ...]
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class DumpRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter out = new PrintWriter(new FileWriter(args[0]));
        Listing listing = currentProgram.getListing();
        for (int i = 1; i + 1 < args.length; i += 2) {
            long start = Long.parseLong(args[i].replaceFirst("(?i)^0x", ""), 16);
            long end = Long.parseLong(args[i + 1].replaceFirst("(?i)^0x", ""), 16);
            out.println("== range 0x" + Long.toHexString(start) + " - 0x" + Long.toHexString(end));
            Address a = toAddr(start);
            while (a.getOffset() < end) {
                Instruction ins = listing.getInstructionAt(a);
                Data d = listing.getDataAt(a);
                if (ins != null) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(String.format("%06x  %-28s", a.getOffset(), ins.toString()));
                    Reference[] refs = ins.getReferencesFrom();
                    for (Reference r : refs) {
                        if (r.getReferenceType().isFlow() && !r.getReferenceType().isCall()
                            && !r.getReferenceType().isJump()) continue;
                        sb.append(" " + r.getReferenceType() + "->0x"
                            + Long.toHexString(r.getToAddress().getOffset()));
                    }
                    out.println(sb);
                    a = a.add(ins.getLength());
                } else if (d != null) {
                    out.println(String.format("%06x  DATA len=%d %s", a.getOffset(), d.getLength(),
                        d.getValue() == null ? "" : d.getValue().toString()));
                    a = a.add(d.getLength());
                } else {
                    out.println(String.format("%06x  UNDEFINED", a.getOffset()));
                    a = a.add(1);
                }
            }
        }
        out.close();
        println("DUMP DONE");
    }
}
