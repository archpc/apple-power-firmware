
/* WARNING: Control flow encountered bad instruction data */

void FUN_0000fc4c(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint extraout_r3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 extraout_s1;
  ulonglong uVar10;
  int in_stack_00000054;
  int in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000068;
  undefined1 in_stack_00000070;
  
  bVar1 = *(byte *)(param_4 + in_stack_00000054);
  uVar4 = (uint)bVar1 + in_stack_0000005c;
  *(char *)(param_4 + in_stack_00000054) = (char)uVar4;
  *(int *)(in_stack_00000058 + 0x44) = *(int *)(in_stack_00000058 + 0x44) + in_stack_0000005c;
  uVar10 = (ulonglong)CONCAT14(bVar1,(undefined *)(uint)*(ushort *)(param_3 + 0x42));
  if ((undefined *)(uint)*(ushort *)(param_3 + 0x42) == PTR_DAT_0000fe20) {
    uVar10 = FUN_000107d6();
    uVar4 = extraout_r3;
  }
  iVar2 = (int)(uVar10 >> 0x20);
  uVar7 = (uint)uVar10;
  uVar5 = uVar4;
  if (7 < (uVar4 & 0xff)) {
    uVar5 = 8;
  }
  uVar6 = (uVar4 - uVar5) + 7;
  uVar8 = 0xff;
  for (uVar5 = uVar4 - (uVar6 & 0xfffffff8); (uVar5 & 0xff) != 0; uVar5 = uVar5 - 1) {
    uVar8 = uVar8 >> 1;
  }
  uVar5 = (uVar6 & 0xff) >> 3;
  if ((uVar4 & 0xff) - iVar2 != 1) {
    iVar3 = iVar2;
    if (0x7ffffffff < uVar10) {
      iVar3 = 8;
    }
    uVar4 = ((iVar2 - iVar3) + 7U & 0xff) >> 3;
    if (uVar5 != uVar4) {
      uVar7 = 0;
      while ((uVar5 - uVar4 & ~((int)(uVar5 - uVar4) >> 0x1f)) != uVar7) {
        in_stack_00000070 = 0;
        iVar2 = FUN_00009fa4(in_stack_00000060 * 0x4000 + (uVar4 + uVar7 & 0xff) +
                             (uint)*(ushort *)(in_stack_00000068 + 0x42) + 6,&stack0x00000070,1);
        uVar7 = uVar7 + 1;
        if (iVar2 != 0) {
          uVar9 = FUN_000107d6();
          VectorAdd(CONCAT44(extraout_s1,uVar9),CONCAT44(extraout_s1,uVar9),4,1);
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      uVar7 = (uint)*(ushort *)(in_stack_00000068 + 0x42);
    }
  }
  in_stack_00000070 = (char)uVar8;
  FUN_00009fa4(uVar7 + in_stack_00000060 * 0x4000 + uVar5 + 6,&stack0x00000070,1);
  FUN_000107d6();
  return;
}

