
void FUN_00001df0(uint param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_r4;
  uint *unaff_r6;
  uint *unaff_r7;
  int iStack00000014;
  uint in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  
  unaff_r6[0x1b] = param_1;
  unaff_r6[0x1b] = unaff_r6[0x1b] | 1;
  iStack00000014 = 0x4b;
  FUN_00000b60(0x12c0);
  unaff_r7[6] = unaff_r7[6] & 0xfffffffb | 3;
  unaff_r7[3] = unaff_r7[3] & 0xfffffffa | 2;
  *unaff_r7 = *unaff_r7 & 0xfffffff3;
  iVar2 = DAT_00001f50;
  iVar3 = DAT_00001f50 + in_stack_00000028 * 0x5c;
  uVar1 = (undefined2)DAT_00001f0c;
  *(undefined2 *)(iVar3 + 0x44) = uVar1;
  *(undefined2 *)(iVar3 + 0x46) = uVar1;
  FUN_0000843c(in_stack_00000028,0);
  FUN_0000843c(in_stack_00000028,1);
  unaff_r6[0x19] = DAT_00001f10 & unaff_r6[0x19];
  unaff_r6[0x19] = unaff_r6[0x19] | 0xe0000;
  unaff_r4[0x1b] = unaff_r4[0x1b] & 0xfff3ffff;
  unaff_r4[0x1b] = unaff_r4[0x1b] & 0xfb7fffff;
  unaff_r6[0x1d] = unaff_r6[0x1d] & ~in_stack_00000018;
  iVar3 = DAT_00001f54;
  *(undefined1 *)(DAT_00001f54 + in_stack_00000028 * 0x88 + 0x85) = 1;
  *(int *)(DAT_00001f58 + in_stack_0000001c) = DAT_00001f58 + in_stack_0000001c + 4;
  *(undefined4 *)(iVar3 + in_stack_00000028 * 0x88) = DAT_00001f5c;
  *(undefined4 *)(iVar2 + in_stack_00000028 * 0x5c) = DAT_00001f60;
  *unaff_r4 = 0x3f;
  unaff_r4[1] = 0xfffffffd;
  unaff_r4[2] = 0xffffffff;
  unaff_r4[7] = 0xfffffffd;
  unaff_r4[8] = 0xffffffff;
  unaff_r4[4] = 0xfffffffd;
  unaff_r4[5] = 0xffffffff;
  *(undefined4 *)(in_stack_00000024 + 4) = DAT_00001f14;
  unaff_r4[3] = 0xffffffff;
  unaff_r4[9] = 0xffffffff;
  unaff_r4[6] = 0xffffffff;
  unaff_r4[0xc] = DAT_00001f18;
  unaff_r4[0xf] = 0xf;
  unaff_r4[0x16] = iStack00000014 << 2;
  unaff_r4[0x17] = DAT_00001f1c;
  *unaff_r6 = DAT_00001f20 & *unaff_r6;
  unaff_r6[7] = unaff_r6[7] & 0xffff;
  unaff_r6[7] = DAT_00001f24 | unaff_r6[7];
  unaff_r4[0x12] = DAT_00001f28;
  *(undefined1 *)(in_stack_00000020 + 0x32) = 1;
  *DAT_00001f64 = 1;
  return;
}

