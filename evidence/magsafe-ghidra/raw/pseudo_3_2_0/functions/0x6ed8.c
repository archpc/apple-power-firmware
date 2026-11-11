// rea decompile_all
// name: FUN_00006ed8
// address: 0x6ed8
// body: available
// range: 0x6ed8-0x724f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00006ed8(uint param_1,int param_2,uint param_3,int param_4,uint param_5,uint param_6,
                 undefined4 *param_7)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  uint local_54;
  uint local_4c;
  uint local_40;
  uint local_34;
  
  if ((param_1 < 2) && (iVar9 = DAT_00007254 + param_1 * 0x88, *(char *)(iVar9 + 0x73) != '\x01')) {
    puVar10 = (undefined1 *)(iVar9 + 0x73);
    iVar9 = DAT_00007254 + param_1 * 0x88;
    if (((*(char *)(iVar9 + 0x85) == '\0') || (param_4 == 0)) ||
       (((param_7 != (undefined4 *)0x0 && ((param_5 & 0x1ff) < 0x105)) &&
        ((-1 < (int)(param_5 << 0x10) ||
         ((((int)(param_5 << 0x15) < 0 || (uVar7 = (param_5 & 0x7fff) >> 0xb, uVar7 == 0)) ||
          (uVar7 * 0x1a < (param_5 & 0x1ff))))))))) {
      pcVar11 = (char *)(iVar9 + 0x85);
      local_34 = param_6 & 7;
      *(char *)(iVar9 + 0x7b) = (char)local_34;
      *(char *)(iVar9 + 0x7a) = (char)param_3;
      *(char *)(iVar9 + 0x74) = (char)param_2;
      *(char *)(iVar9 + 0x78) = (char)param_4;
      uVar4 = (ushort)param_5;
      *(ushort *)(iVar9 + 0x76) = uVar4;
      param_5 = DAT_00007250 & param_5;
      iVar14 = DAT_00007258 + param_1 * 0x1cc;
      uVar7 = (uint)*(byte *)(iVar14 + 0x3e);
      bVar3 = *(byte *)(iVar14 + 0x3f);
      iVar12 = 3;
      if ((*pcVar11 != '\0') && (1 < uVar7)) {
        if ((short)uVar4 < 0) {
          iVar12 = 2;
        }
        else {
          iVar12 = (uint)(param_5 < 0x1b) << 1;
        }
        if (param_4 == 0) {
          iVar12 = 2;
        }
        if ((*(char *)(iVar14 + 0x10) != '\x02') && (param_2 != 0)) {
          if (*(char *)(iVar14 + 0x28) == '\0') {
            *puVar10 = 1;
            FUN_00006c58(param_1,0x20);
            return;
          }
          if (bVar3 < 2) {
            iVar12 = 3;
          }
        }
      }
      if (*(char *)(iVar9 + 0x72) == '\x01') {
        iVar12 = 0;
        *(undefined1 *)(iVar9 + 0x72) = 0;
      }
      if (*pcVar11 == '\0') {
        if (param_2 == 0) {
          uVar8 = (uint)*(byte *)(iVar14 + 0x14) << 5 | (uint)*(byte *)(iVar14 + 0x15) << 8;
        }
        else {
          uVar8 = 0x100;
        }
        bVar3 = *(byte *)(iVar9 + param_2 * 3 + 4);
        puVar13 = (undefined4 *)(iVar9 + 0x10);
        for (uVar15 = local_34; uVar15 != 0; uVar15 = uVar15 - 1) {
          uVar5 = *param_7;
          param_7 = param_7 + 1;
          *puVar13 = uVar5;
          puVar13 = puVar13 + 1;
        }
        uVar8 = param_3 + (uint)bVar3 * 0x200 | uVar8 | local_34 << 0xc | 0x40;
        *(uint *)(iVar9 + 0x30) = uVar8;
        param_7 = (undefined4 *)(iVar9 + 0x10);
        uVar5 = 0;
      }
      else {
        local_4c = (uint)(short)uVar4;
        local_40 = 0;
        bVar16 = (int)local_4c < 0;
        bVar1 = true;
        if (param_4 != 0) {
          if (param_5 < 0x1b) {
            uVar4 = uVar4 | 0x8000;
          }
          local_4c = (uint)(short)uVar4;
          if ((int)local_4c < 0) {
            if ((int)(local_4c << 0x15) < 0) {
              local_4c = local_4c & 0xfe00;
              local_40 = 0;
            }
            else {
              uVar8 = (local_4c & 0x7fff) >> 0xb;
              if (param_5 < uVar8 * 0x1a + 0x1a) {
                local_40 = uVar8 * -0x1a + param_5;
              }
              else {
                local_40 = 0x1a;
              }
            }
            local_34 = FUN_00008ea2((local_40 & 0xffff) + 2);
            bVar1 = false;
            bVar16 = true;
          }
          else {
            bVar1 = true;
            bVar16 = false;
            local_34 = 0;
            local_40 = param_5;
          }
        }
        if (param_2 == 0) {
          local_54 = (uint)*(byte *)(iVar14 + 0x14) << 5 |
                     uVar7 << 6 | (uint)*(byte *)(iVar14 + 0x15) << 8;
        }
        else {
          local_54 = (uint)bVar3 << 6 | 0x100;
        }
        bVar3 = *(byte *)(iVar9 + param_2 * 3 + 4);
        puVar13 = (undefined4 *)(iVar9 + 0x10);
        uVar15 = 0;
        FUN_000001a0(puVar13,0,0x20);
        if (bVar1) {
          bVar6 = (byte)(local_34 << 2);
          bVar2 = 0;
        }
        else {
          *(short *)puVar13 = (short)local_4c;
          bVar2 = 2;
          bVar6 = (byte)local_40;
        }
        uVar8 = (local_34 & 0xff) << 0xc | (uint)(param_4 != 0) * 0x8000 | local_54 | param_3 |
                (uint)bVar3 << 9;
        for (; bVar6 != uVar15; uVar15 = uVar15 + 1) {
          *(undefined1 *)((int)puVar13 + (uint)bVar2) = *(undefined1 *)((int)param_7 + uVar15);
          bVar2 = bVar2 + 1;
        }
        if ((param_4 == 0) || (bVar16)) {
          uVar5 = 0;
          bVar3 = (byte)local_34;
          param_7 = puVar13;
        }
        else {
          uVar8 = uVar8 | local_4c << 0x10;
          bVar3 = FUN_00008ea2(local_40 & 0xffff);
          uVar5 = 1;
        }
        *(uint *)(iVar9 + 0x30) = uVar8;
        local_34 = (uint)bVar3;
      }
      FUN_00008ab0(param_1,param_2,iVar12,local_34,uVar8,uVar5,param_7);
      uVar5 = FUN_00000b70();
      *puVar10 = 1;
      iVar12 = FUN_00006c1c(param_1);
      if (iVar12 == 0) {
        if ((((*(byte *)(iVar9 + 0x71) - 1 < 2) || (*(char *)(iVar9 + 0x79) == '\x06')) &&
            ((param_2 - 1U & 0xff) < 2)) && ((*pcVar11 == '\0' || (uVar7 < 2)))) {
          FUN_0000c908(param_1,4,2,DAT_0000725c);
        }
        else {
          FUN_00008b20(param_1);
        }
      }
    }
    else {
      uVar5 = FUN_00000b70();
      *puVar10 = 1;
      FUN_00006c58(param_1,0x10);
    }
    FUN_00000b78(uVar5);
  }
  return;
}

