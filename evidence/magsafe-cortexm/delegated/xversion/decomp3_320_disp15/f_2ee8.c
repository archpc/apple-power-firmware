
void FUN_00002ee8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00008c00(param_1,0,param_3,param_4,param_4);
  FUN_00008c64(param_1);
  iVar1 = *(int *)(DAT_00002fa0 + param_1 * 4);
  iVar3 = 0x118;
  *(uint *)(iVar1 + 0x128) = DAT_00002f98 & *(uint *)(iVar1 + 0x128);
  *(undefined4 *)(iVar1 + 0x118) = DAT_00002f9c;
  FUN_0000cac8(param_1,0,0xe);
  iVar1 = DAT_00002fa4 + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x21) = 0;
  *(undefined1 *)(iVar1 + 0x24) = 0;
  *(undefined1 *)(iVar1 + 0x20) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 0;
  iVar2 = DAT_00002fa8 + param_1 * 0xf0;
  *(undefined2 *)(iVar2 + 0xa8) = 0;
  *(undefined2 *)(iVar2 + 0xa6) = 0;
  *(undefined1 *)(iVar2 + 0xa4) = 0;
  *(undefined1 *)(iVar1 + 0x2c) = 0;
  *(undefined1 *)(iVar1 + 0x45) = 0;
  *(undefined4 *)(iVar1 + iVar3) = 0;
  iVar3 = 0x43;
  *(undefined4 *)(iVar1 + 0x10c) = 0;
  *(undefined4 *)(iVar1 + 0x11c) = 0;
  *(undefined4 *)(iVar1 + 0x104) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined1 *)(iVar1 + 0x25) = 0;
  FUN_00002fb0(param_1);
  *(undefined1 *)(iVar1 + 0x176) = 0;
  *(undefined2 *)(iVar1 + 0x174) = 0;
  *(undefined1 *)(iVar1 + iVar3) = 0;
  *(undefined1 *)(iVar2 + 0xe5) = 0;
  *(undefined1 *)(iVar2 + 0xed) = 0;
  *(undefined1 *)(DAT_00002fac + param_1) = 0;
  return;
}

