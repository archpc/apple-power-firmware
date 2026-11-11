// Minimal smoke test: verify the supported headless path end to end.
// Imports are done by analyzeHeadless; this script only checks the program,
// disassembles one known Thumb prologue at file offset 0x10, and exports
// its address and bytes.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import java.io.*;

public class SmokeOffset10 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter out = new PrintWriter(new FileWriter(args[0]));
        Address a10 = toAddr(0x10);
        Memory mem = currentProgram.getMemory();
        byte[] b = new byte[8];
        mem.getBytes(a10, b);
        StringBuilder hex = new StringBuilder();
        for (byte x : b) hex.append(String.format("%02x", x));
        disassemble(a10);
        Instruction ins = getInstructionAt(a10);
        out.println("language=" + currentProgram.getLanguage().getLanguageID());
        out.println("bytes@0x10=" + hex);
        out.println("instr=" + (ins != null ? ins.toString() : "NONE"));
        out.println("nextAddr=" + (ins != null
            ? "0x" + Long.toHexString(ins.getMaxAddress().getOffset() + 1) : "-"));
        out.close();
        println("SMOKE instr=" + (ins != null ? ins.toString() : "NONE"));
    }
}
