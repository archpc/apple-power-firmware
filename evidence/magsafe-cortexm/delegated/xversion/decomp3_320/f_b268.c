
void FUN_0000b268(int param_1,uint *param_2,int param_3,code *param_4)

{
  bool bVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 auStack_40 [4];
  undefined1 local_3c;
  
  iVar3 = DAT_0000b440;
  uVar5 = *param_2;
  if (param_3 == 3) {
    *(undefined1 *)(DAT_0000b440 + 0x18) = 1;
    FUN_00009728(param_2[2]);
  }
  lVar9 = FUN_00000e80();
  uVar2 = (ulonglong)DAT_0000b428;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_0000991c();
  *(ulonglong *)(DAT_0000b444 + 0x68) = lVar9 + uVar2;
  FUN_00009dec();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar8 & 1) == 1);
  }
  if (param_1 == 1) {
    FUN_00002e68();
    iVar4 = DAT_0000b448;
    uVar8 = uVar5 >> 0x1c & 7;
    if ((int)uVar5 < 0) {
      iVar6 = uVar8 + 7;
    }
    else {
      iVar6 = (uVar5 >> 0x1c) - 1;
    }
    uVar7 = *(uint *)(*(int *)(*(int *)(DAT_0000b448 + 0x44) + 0x11c) + iVar6 * 4 + 8);
    if (*(char *)(*(int *)(DAT_0000b448 + 0x44) + 0x21) != '\0') {
      *(undefined1 *)(iVar3 + 0x1b) = 1;
                    /* WARNING: Could not recover jumptable at 0x0000b2f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint)(byte)(&DAT_0000b2f4)[uVar7 >> 0x1e] * 2 + 0xb2f6))();
      return;
    }
    if (((uVar8 == 0) || (*(byte *)(*(int *)(DAT_0000b448 + 0x58) + 0x29) < uVar8)) ||
       (2 < *(uint *)(uVar8 * 4 + *(int *)(DAT_0000b448 + 0x58) + 0x98) >> 0x1e)) {
      *(undefined1 *)(DAT_0000b448 + 0x69) = 0;
      local_3c = 4;
    }
    else {
      iVar6 = FUN_00002a5c(1,uVar5);
      if (iVar6 == 0) {
        local_3c = 3;
      }
      else {
        *(undefined1 *)(iVar4 + 0x69) = 0;
        local_3c = 4;
      }
    }
    (*param_4)(1,auStack_40);
    *(undefined1 *)(iVar3 + 0x1b) = 0;
  }
  return;
}

