// List inbound references from OUTSIDE a given [start,end) range to any address
// inside it. Usage: XrefRange.java <out> <hexStart> <hexEnd>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.symbol.Reference;
import java.io.*;
import java.util.*;

public class XrefRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long start = Long.parseLong(args[1].replaceFirst("(?i)^0x", ""), 16);
        long end = Long.parseLong(args[2].replaceFirst("(?i)^0x", ""), 16);
        PrintWriter out = new PrintWriter(new FileWriter(args[0]));
        AddressSet inside = new AddressSet(toAddr(start), toAddr(end - 1));
        AddressSet already = new AddressSet();
        for (long a = start; a < end; a += 2) {
            Address t = toAddr(a);
            for (Reference ref : getReferencesTo(t)) {
                Address from = ref.getFromAddress();
                long f = from.getOffset();
                if (f >= start && f < end) continue; // internal
                if (already.contains(from)) continue;
                already.add(from);
                out.println("0x" + Long.toHexString(f) + " -> 0x" + Long.toHexString(a)
                    + " " + ref.getReferenceType());
            }
        }
        out.close();
        println("XREFRANGE DONE");
    }
}
