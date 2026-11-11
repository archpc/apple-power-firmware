
void FUN_00006730(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  FUN_00008ab0(param_1,0,param_3,param_4,param_4);
  iVar1 = DAT_000067bc + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x20) = 0;
  iVar2 = DAT_000067c0 + param_1 * 0xf0;
  *(undefined2 *)(iVar2 + 0xa8) = 0;
  *(undefined2 *)(iVar2 + 0xa6) = 0;
  *(undefined4 *)(iVar1 + 0x118) = 0;
  *(undefined4 *)(iVar1 + 0x104) = 0;
  *(undefined1 *)(iVar1 + 0x24) = 0;
  if (param_1 < 2) {
    *(undefined1 *)(DAT_000067c4 + param_1 * 0x88 + 0x7c) = 0;
  }
  *(undefined1 *)(iVar2 + 0xe5) = 0;
  *(undefined1 *)(iVar1 + 0x174) = 0;
  *(undefined1 *)(iVar1 + 0x43) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  FUN_00002ef8(param_1);
  FUN_0000c838(param_1,0xc);
  FUN_0000c838(param_1,0xd);
  *(undefined1 *)(iVar1 + 0x1c8) = 0;
  *(undefined1 *)(iVar1 + 0x176) = 0;
  *(undefined1 *)(iVar1 + 0x175) = 0;
  *(undefined1 *)(iVar2 + 0xed) = 0;
  *(undefined1 *)(DAT_000067c8 + param_1) = 0;
  return;
}

