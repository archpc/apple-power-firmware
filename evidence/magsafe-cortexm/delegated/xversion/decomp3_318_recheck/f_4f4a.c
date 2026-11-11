
void FUN_00004f4a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack00000000;
  uint uStack00000004;
  undefined4 uStack00000008;
  uint uStack0000000c;
  int iStack00000014;
  undefined4 uStack00000018;
  byte *in_stack_00000024;
  uint uStack00000034;
  undefined4 in_stack_00000038;
  
  iStack00000014 = param_1 << 0xb;
  uStack00000034 = (uint)*in_stack_00000024;
  uStack00000004 = (uint)*(ushort *)(in_stack_00000024 + 2);
  uStack00000008 = *(undefined4 *)(in_stack_00000024 + 8);
  uStack0000000c = (uint)in_stack_00000024[0xc];
  uStack00000018 = DAT_00004fbc;
  uStack00000000 = in_stack_00000038;
  FUN_000062a8(param_4,2,in_stack_00000024[1],uStack00000034);
  return;
}

