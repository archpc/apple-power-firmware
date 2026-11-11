// rea decompile_all
// name: FUN_0000967c
// address: 0x967c
// body: available
// range: 0x967c-0x969b inclusive
// range: 0x96c0-0x9927 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 FUN_0000967c(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 local_4 [4];
  
  FUN_00012a9c();
  FUN_0000094c(param_1);
  local_4[0] = (undefined1)param_1;
  switch(param_1) {
  case 0:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xb);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 2;
    goto LAB_0000991a;
  case 1:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xc);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 5;
    goto LAB_0000991a;
  case 2:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xd);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 3:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xe);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 4:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xf);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 5:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x10);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 6:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x11);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 7:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(10);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 3;
    goto LAB_0000991a;
  case 8:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x12);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 9:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x13);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 10:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x14);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 4;
    goto LAB_0000991a;
  case 0xb:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x15);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xc:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x16);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xd:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x17);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xe:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x18);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xf:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x19);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0x10:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x1a);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0x11:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x1b);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  default:
    if (DAT_20001859 == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x1c);
      FUN_0000906c(local_4,1);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
  }
  uVar2 = 7;
LAB_0000991a:
  FUN_0000d984(uVar2);
  FUN_00000bac();
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009944(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return *(undefined1 *)(DAT_00009940 + 0x42);
}

