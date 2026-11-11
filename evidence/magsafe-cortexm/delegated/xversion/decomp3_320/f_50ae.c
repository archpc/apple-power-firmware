
void FUN_000050ae(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r7;
  undefined4 uStack00000000;
  uint uStack00000004;
  undefined4 uStack00000008;
  uint uStack0000000c;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  byte *in_stack_0000001c;
  uint uStack0000002c;
  undefined4 in_stack_00000030;
  
  *(undefined1 *)(param_4 + unaff_r7 * param_1 + 0xa9) = 2;
  uStack0000002c = (uint)*in_stack_0000001c;
  uStack00000004 = (uint)*(ushort *)(in_stack_0000001c + 2);
  uStack00000008 = *(undefined4 *)(in_stack_0000001c + 8);
  uStack0000000c = (uint)in_stack_0000001c[0xc];
  uStack00000018 = DAT_000050f8;
  uStack00000014 = 0x80;
  uStack00000010 = 2;
  uStack00000000 = in_stack_00000030;
  FUN_00006328();
  return;
}

