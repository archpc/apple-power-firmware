
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010ac0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *extraout_r3;
  int unaff_r4;
  undefined4 unaff_r7;
  undefined8 uVar4;
  int in_stack_00000010;
  undefined1 in_stack_00000014;
  int in_stack_00000024;
  ushort in_stack_0000002c;
  undefined4 in_stack_00000034;
  undefined1 in_stack_0000003c;
  ushort *in_stack_00000040;
  undefined1 in_stack_0000004c;
  int in_stack_00000050;
  uint in_stack_00000054;
  int in_stack_00000060;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000074;
  undefined1 in_stack_00000078;
  undefined1 uStack00000079;
  undefined1 uStack0000007a;
  undefined1 uStack0000007b;
  undefined1 in_stack_0000007c;
  undefined1 in_stack_00000080;
  
  *(short *)(in_stack_00000074 + 0x40) = (short)in_stack_00000068;
  *(short *)(unaff_r4 + 0x32) = (short)in_stack_00000068 + 0x20;
  if (in_stack_00000068 == DAT_00010c08) {
    FUN_000107d6();
    return;
  }
  in_stack_00000080 = 0x7f;
  iVar3 = FUN_00009fac(in_stack_00000068 + 0x4000);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_000001a0(&stack0x00000078,0xff);
  in_stack_0000007c = (undefined1)((uint)unaff_r7 >> 0x18);
  uStack0000007b = (undefined1)((uint)unaff_r7 >> 0x10);
  uStack0000007a = (undefined1)((uint)unaff_r7 >> 8);
  uStack00000079 = (undefined1)unaff_r7;
  in_stack_00000078 = 0x10;
  iVar3 = FUN_00009fac(&LAB_00004000_1 + in_stack_00000068,&stack0x00000078,5);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  in_stack_00000080 = 0x3f;
  uVar4 = FUN_00009fac(in_stack_00000068 + 0x4000,&stack0x00000080,1);
  if ((int)uVar4 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_0000ff42(0,(int)((ulonglong)uVar4 >> 0x20),in_stack_0000006c);
  in_stack_00000078 = in_stack_0000004c;
  iVar3 = FUN_00009fac((uint)*extraout_r3 + in_stack_00000050,&stack0x00000078,1);
  uVar2 = ram0x00000005;
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  uVar1 = *in_stack_00000040;
  in_stack_00000080 = in_stack_0000003c;
  iVar3 = FUN_00009fac(in_stack_00000024,&stack0x00000080,1);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_000001a0(&stack0x00000078,0xff);
  in_stack_0000007c = (undefined1)((uint)uVar2 >> 0x18);
  uStack0000007b = (undefined1)((uint)uVar2 >> 0x10);
  uStack0000007a = (undefined1)((uint)uVar2 >> 8);
  uStack00000079 = (undefined1)uVar2;
  in_stack_00000078 = (undefined1)in_stack_00000060;
  iVar3 = FUN_00009fac(in_stack_00000024 + 1,&stack0x00000078,5);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  in_stack_00000080 = 0x3f;
  iVar3 = FUN_00009fac(in_stack_00000024,&stack0x00000080,1);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  in_stack_00000078 = in_stack_00000014;
  iVar3 = FUN_00009fac((uint)uVar1 + in_stack_00000050,&stack0x00000078,1);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  *in_stack_00000040 = in_stack_0000002c;
  *(undefined1 *)(in_stack_0000006c + in_stack_00000060 + 0x10) = 0;
  if (2 < in_stack_00000054) {
    FUN_000107d6();
    return;
  }
  uVar4 = FUN_0000a020(in_stack_00000010 + in_stack_00000050,in_stack_00000034);
  if ((int)uVar4 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_0000ff42(0,(int)((ulonglong)uVar4 >> 0x20),in_stack_0000006c);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

