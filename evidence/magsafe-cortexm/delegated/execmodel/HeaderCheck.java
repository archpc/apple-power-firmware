// Step 2: vector-header / reset-target check for the flat A2363 images.
// Read-only: dumps words, listing state and decodability of the reset target.
// args: outTxt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import java.io.*;

public class HeaderCheck extends GhidraScript {
    String hex(byte[] b) {
        StringBuilder s = new StringBuilder();
        for (byte x : b) s.append(String.format("%02x", x));
        return s.toString();
    }
    @Override
    public void run() throws Exception {
        PrintWriter out = new PrintWriter(new FileWriter(getScriptArgs()[0]));
        Memory mem = currentProgram.getMemory();
        out.println("languageID=" + currentProgram.getLanguageID());
        out.println("language=" + currentProgram.getLanguage().getLanguageID());
        out.println("cspec=" + currentProgram.getCompilerSpec().getCompilerSpecID());
        out.println("imageBase=" + currentProgram.getImageBase());
        out.println("memory=" + mem.getMinAddress() + ".." + mem.getMaxAddress()
            + " size=" + mem.getNumAddresses());
        byte[] h = new byte[16];
        mem.getBytes(toAddr(0), h);
        out.println("bytes@0x0=" + hex(h));
        for (int i = 0; i < 4; i++) {
            long w = 0;
            for (int j = 3; j >= 0; j--) w = (w << 8) | (h[i * 4 + j] & 0xff);
            out.println("word[" + i + "]@0x" + Integer.toHexString(i * 4)
                + "=0x" + String.format("%08x", w));
        }
        // listing state of the header words (loader artifact check)
        for (int i = 0; i < 4; i++) {
            Address a = toAddr(i * 4);
            Data d = getDataAt(a);
            Instruction ins = getInstructionAt(a);
            Function f = getFunctionContaining(a);
            out.println("hdr 0x" + Integer.toHexString(i * 4)
                + " codeUnit=" + (d != null ? d.toString() : (ins != null ? ins.toString() : "none"))
                + " ins=" + (ins != null ? ins.toString() : "-")
                + " func=" + (f != null ? f.getName() + "@0x" + Long.toHexString(f.getEntryPoint().getOffset()) : "-"));
        }
        // reset / NMI / HardFault targets
        long[] tgts = {0x10f7cL, 0x10fa0L};
        for (long t : tgts) {
            Address a = toAddr(t);
            out.println("--- target 0x" + Long.toHexString(t));
            byte[] b = new byte[32];
            mem.getBytes(a, b);
            out.println("  bytes=" + hex(b));
            Function fc = getFunctionContaining(a);
            out.println("  functionContaining=" + (fc != null ? fc.getName() : "NONE"));
            Data d0 = getDataAt(a);
            out.println("  dataAt=" + (d0 != null ? d0.toString() + " len=" + d0.getLength() : "NONE"));
            Instruction pre = getInstructionAt(a);
            out.println("  insBefore=" + (pre != null ? pre.toString() : "NONE"));
            disassemble(a);
            Instruction post = getInstructionAt(a);
            out.println("  disassemble()->" + (post != null ? post.toString() : "NONE"));
            if (post != null) {
                Function fn = getFunctionAt(a);
                out.println("  functionAtAfter=" + (fn != null ? fn.getName() : "NONE"));
                out.println("  next=" + post.getMaxAddress().add(1));
            }
            // pointer-table plausibility of the 32 bytes as 8 little-endian dwords
            StringBuilder w = new StringBuilder();
            for (int i = 0; i < 8; i++) {
                long v = 0;
                for (int j = 3; j >= 0; j--) v = (v << 8) | (b[i * 4 + j] & 0xff);
                w.append(String.format("0x%08x ", v));
            }
            out.println("  dwords=" + w.toString().trim());
        }
        // reset target inside any pointer-table-ish region? report the run of
        // 4-byte-aligned words whose top byte is 0x20 (SRAM) or 0xe0/0x40 (PPB/APB)
        byte[] b = new byte[4];
        int run = 0;
        long start = -1;
        StringBuilder runs = new StringBuilder();
        for (long a = 0x10f00L; a < 0x11050L; a += 4) {
            mem.getBytes(toAddr(a), b);
            long v = (b[3] & 0xffL) << 24 | (b[2] & 0xffL) << 16 | (b[1] & 0xffL) << 8 | (b[0] & 0xffL);
            boolean ptrish = ((v >> 24) == 0x20) || ((v >> 24) == 0xe0) || ((v >> 24) == 0x40);
            if (ptrish) { if (run == 0) start = a; run++; }
            else { if (run >= 2) runs.append(" [0x" + Long.toHexString(start) + "+" + run + "]"); run = 0; }
        }
        if (run >= 2) runs.append(" [0x" + Long.toHexString(start) + "+" + run + "]");
        out.println("ptrishRuns(0x20/0xe0/0x40 top byte, >=2 words) in 0x10f00..0x11050:" + runs);
        out.close();
        println("HEADERCHECK done");
    }
}
