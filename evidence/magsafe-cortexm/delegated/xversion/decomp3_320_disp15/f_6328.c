
void FUN_00006328(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined2 param_6,undefined4 param_7,undefined2 param_8,
                 undefined1 param_9,undefined4 param_10,undefined2 param_11)

{
  int iVar1;
  
  iVar1 = DAT_00006370 + param_1 * 0xf0;
  *(undefined2 *)(iVar1 + 0xb0) = param_8;
  *(undefined1 *)(iVar1 + 0xac) = param_3;
  *(undefined1 *)(iVar1 + 0xab) = param_2;
  *(undefined1 *)(iVar1 + 0xaa) = param_4;
  *(undefined4 *)(iVar1 + 0xb4) = param_7;
  *(undefined1 *)(iVar1 + 0xad) = param_5;
  *(undefined2 *)(iVar1 + 0xc0) = param_11;
  *(undefined4 *)(iVar1 + 0xbc) = param_10;
  *(undefined1 *)(iVar1 + 0xb8) = param_9;
  *(undefined2 *)(iVar1 + 0xae) = param_6;
  FUN_00003258(param_1,0x24);
  return;
}

