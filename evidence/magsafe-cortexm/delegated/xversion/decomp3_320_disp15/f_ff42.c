
void FUN_0000ff42(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r3;
  int iVar6;
  int unaff_r5;
  uint uVar7;
  int unaff_r6;
  ulonglong uVar8;
  int iStack0000006c;
  int in_stack_00000070;
  int in_stack_00000074;
  undefined1 in_stack_00000078;
  
  bVar1 = *(byte *)(param_3 + in_stack_00000070);
  uVar5 = (uint)bVar1 + unaff_r6;
  *(char *)(param_3 + in_stack_00000070) = (char)uVar5;
  *(int *)(unaff_r5 + 0x40) = *(int *)(unaff_r5 + 0x40) + unaff_r6;
  iStack0000006c = 0x40;
  uVar8 = (ulonglong)CONCAT14(bVar1,(uint)*(ushort *)(in_stack_00000074 + 0x40));
  if (*(ushort *)(in_stack_00000074 + 0x40) == DAT_0000fffc) {
    uVar8 = FUN_000107d6();
    uVar5 = extraout_r3;
  }
  iVar3 = (int)(uVar8 >> 0x20);
  uVar2 = (uint)uVar8;
  uVar4 = uVar5 & 0xff;
  iVar6 = uVar4 - 8;
  if (uVar4 < 8) {
    iVar6 = 0;
  }
  uVar7 = 0xff;
  for (uVar5 = uVar5 - (iVar6 + 7U & 0x1f8); (uVar5 & 0xff) != 0; uVar5 = uVar5 - 1) {
    uVar7 = uVar7 >> 1;
  }
  uVar5 = (iVar6 + 7U & 0xff) >> 3;
  if (uVar4 - iVar3 != 1) {
    iVar3 = iVar3 + -8;
    if (uVar8 < 0x800000000) {
      iVar3 = 0;
    }
    uVar4 = (iVar3 + 7U & 0xff) >> 3;
    if (uVar5 != uVar4) {
      iVar3 = 0;
      while (iVar3 < (int)(uVar5 - uVar4)) {
        in_stack_00000078 = 0;
        iVar6 = FUN_00009fac((uVar4 + iVar3 & 0xff) +
                             (uint)*(ushort *)(in_stack_00000074 + iStack0000006c) + 0x4006,
                             &stack0x00000078,1);
        iVar3 = iVar3 + 1;
        if (iVar6 != 0) {
          FUN_000107d6();
          return;
        }
      }
      uVar2 = (uint)*(ushort *)(in_stack_00000074 + iStack0000006c);
    }
  }
  in_stack_00000078 = (char)uVar7;
  FUN_00009fac(uVar5 + uVar2 + 0x4006,&stack0x00000078,1);
  FUN_000107d6();
  return;
}

