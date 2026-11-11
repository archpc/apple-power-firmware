
void FUN_00000fd8(undefined1 *param_1,undefined1 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  iVar2 = 0;
  piVar5 = DAT_000010b4;
  while( true ) {
    if (iVar2 == 8) {
                    /* WARNING: Subroutine does not return */
      FUN_00000f3c(DAT_000010b8);
    }
    if (*piVar5 == 0) break;
    piVar5 = piVar5 + 1;
    iVar2 = iVar2 + 1;
  }
  *piVar5 = (int)param_1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  param_1[9] = 1;
  *param_1 = param_2;
  param_1[1] = (char)iVar2;
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar7 = *(uint *)(param_1 + 0x14);
  puVar8 = *(undefined4 **)(param_1 + 0x18);
  FUN_000001a0(puVar8,0x55,uVar7);
  *puVar8 = DAT_000010b0;
  uVar7 = uVar7 & 0xfffffffc;
  puVar4 = (undefined4 *)((int)puVar8 + (uVar7 - 0x40));
  *(undefined4 **)(param_1 + 0x10) = puVar4;
  *(undefined4 *)((int)puVar8 + (uVar7 - 8)) = DAT_000010bc;
  *(undefined4 *)((int)puVar8 + (uVar7 - 4)) = 0x1000000;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0xc)) = 0;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x10)) = 0;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x14)) = 0;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x18)) = 0;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x1c)) = 0;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x24)) = 9;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x28)) = 10;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x2c)) = 0xb;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x30)) = 0xc;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x34)) = 0xd;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x38)) = 0xe;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x3c)) = 0xf;
  *puVar4 = 0x10;
  *(undefined4 *)((int)puVar8 + (uVar7 - 0x20)) = uVar3;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  FUN_00000f54(param_1);
  return;
}

