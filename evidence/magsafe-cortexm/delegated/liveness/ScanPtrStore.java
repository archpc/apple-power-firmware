// Task 2: enumerate pointer stores and indirect calls in the seeded 3.1.8 program.
// Usage (read-only, existing project):
//   analyzeHeadless /Users/sein/gp_execmodel execmodel318_seed -process <prog> -noanalysis -readOnly \
//     -scriptPath evidence/magsafe-cortexm/delegated/liveness -postScript ScanPtrStore.java <outCsv>
// Addresses are FILE OFFSETS (base-0 import).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ScanPtrStore extends GhidraScript {
    static final long IMG_END = 0x14608L;

    private boolean inImage(long v) { return v >= 0 && v < IMG_END; }

    @Override
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        PrintWriter w = new PrintWriter(new FileWriter(out));
        w.println("kind,func_entry,func_inbound,insn_addr,mnemonic,operands,reg,disp,value,note");
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();
        int nFuncs = 0, nNoInbound = 0, nStores = 0, nPtrStores = 0, nIndCall = 0;

        for (Function f : fm.getFunctions(true)) {
            nFuncs++;
            Address ep = f.getEntryPoint();
            int inbound = rm.getReferenceCountTo(ep) - 0;   // includes data refs
            if (inbound == 0) nNoInbound++;
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            List<Instruction> body = new ArrayList<>();
            while (it.hasNext()) body.add(it.next());

            for (int i = 0; i < body.size(); i++) {
                Instruction ins = body.get(i);
                String mn = ins.getMnemonicString().toUpperCase();
                int nOps = ins.getNumOperands();

                // ---- indirect calls / pc loads ----
                boolean indCall = false;
                String note = "";
                if (mn.equals("BLX") || mn.equals("BX")) {
                    if (nOps >= 1) {
                        Object o = ins.getOpObjects(0).length > 0 ? ins.getOpObjects(0)[0] : null;
                        if (o instanceof Register) {
                            Register r = (Register) o;
                            boolean isLr = r.getName().equalsIgnoreCase("lr") || r.getName().equalsIgnoreCase("r14");
                            if (mn.equals("BLX") || !isLr) indCall = true;
                        }
                    }
                } else if (mn.equals("MOV") && nOps == 2) {
                    Object[] d = ins.getOpObjects(0);
                    Object[] s = ins.getOpObjects(1);
                    if (d.length > 0 && s.length > 0 && d[0] instanceof Register && s[0] instanceof Register
                            && ((Register) d[0]).getName().equalsIgnoreCase("pc")) {
                        indCall = true;
                    }
                }
                if (indCall) {
                    nIndCall++;
                    w.println("indcall," + hex(ep) + "," + inbound + "," + hex(ins.getAddress())
                            + "," + mn + ",\"" + ins.toString().replace("\"", "'") + "\",,,,indirect-transfer");
                }

                // ---- stores: STR rX, [rY, #imm] ----
                if (!mn.startsWith("STR") || mn.startsWith("STRB") || mn.startsWith("STRH")
                        || mn.startsWith("STRD")) continue;
                if (nOps < 2) continue;
                Object[] d0 = ins.getOpObjects(0);
                Object[] d1 = ins.getOpObjects(1);
                if (d0.length != 1 || !(d0[0] instanceof Register)) continue;
                if (d1.length == 0 || !(d1[d1.length - 1] instanceof Scalar)) continue;
                // memory operand shape: has a register base
                boolean memShape = false;
                for (Object o : d1) if (o instanceof Register) memShape = true;
                if (!memShape) continue;
                Register src = (Register) d0[0];
                Register base = null;
                for (int k = d1.length - 1; k >= 0; k--)
                    if (d1[k] instanceof Register) { base = (Register) d1[k]; break; }
                long disp = ((Scalar) d1[d1.length - 1]).getUnsignedValue();
                nStores++;

                // Does src hold an address? scan backwards within the same function
                long val = -1;
                String how = "";
                for (int j = i - 1; j >= 0 && j >= i - 40; j--) {
                    Instruction p = body.get(j);
                    Object[] pd = p.getNumOperands() > 0 ? p.getOpObjects(0) : new Object[0];
                    boolean writes = false;
                    for (Object o : pd) if (o instanceof Register && ((Register) o).equals(src)) writes = true;
                    if (p.getMnemonicString().toUpperCase().startsWith("LDR")
                            || p.getMnemonicString().toUpperCase().startsWith("POP")) {
                        for (Object o : pd) if (o instanceof Register && ((Register) o).equals(src)) writes = true;
                    }
                    if (!writes) continue;
                    // scalar reference out of this instruction into the image?
                    for (int k = 0; k < p.getNumOperands(); k++) {
                        Object[] po = p.getOpObjects(k);
                        for (Object o : po) {
                            if (o instanceof Scalar) {
                                long s = ((Scalar) o).getUnsignedValue();
                                if (inImage(s) && s > 0x10) { val = s; how = p.getMnemonicString(); }
                            }
                        }
                    }
                    if (val < 0) {
                        // adr/add pc-relative or ldr-literal: check references from this insn
                        for (Reference rr : p.getReferencesFrom()) {
                            Address t = rr.getToAddress();
                            if (t != null && inImage(t.getOffset()) && t.getOffset() > 0x10) {
                                val = t.getOffset(); how = p.getMnemonicString() + "(ref)";
                            }
                        }
                    }
                    break;  // nearest writer only
                }
                if (val >= 0) {
                    nPtrStores++;
                    boolean codeish = (val & 1) == 1;
                    w.println("ptrstore," + hex(ep) + "," + inbound + "," + hex(ins.getAddress())
                            + "," + mn + ",\"" + ins.toString().replace("\"", "'") + "\","
                            + src.getName() + "," + hex(disp) + "," + hex(val) + ","
                            + (codeish ? "odd(maybe-code)" : "even(data)")
                            + (disp == 0x60 ? ";DISP60" : "") + ";via " + how);
                } else if (disp == 0x60) {
                    w.println("store60_noval," + hex(ep) + "," + inbound + "," + hex(ins.getAddress())
                            + "," + mn + ",\"" + ins.toString().replace("\"", "'") + "\","
                            + src.getName() + "," + hex(disp) + ",,no-value-found");
                }
            }
        }
        w.close();
        println("functions=" + nFuncs + " noInbound=" + nNoInbound + " stores=" + nStores
                + " ptrStores=" + nPtrStores + " indCalls=" + nIndCall);
    }

    private String hex(long v) { return "0x" + Long.toHexString(v); }
}
