
void FUN_00008ab0(int param_1,int param_2,undefined1 param_3,undefined1 param_4,uint param_5,
                 undefined1 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_00008b14 + param_1 * 4);
  if (param_2 == 2) {
    *(uint *)(iVar2 + 0xe4) = *(uint *)(iVar2 + 0xe4) | 0x400;
  }
  iVar1 = DAT_00008b18 + param_1 * 0x5c;
  *(undefined1 *)(iVar1 + 0x52) = param_6;
  *(undefined1 *)(iVar1 + 0x50) = param_4;
  *(undefined4 *)(iVar2 + 0xf8) = *(undefined4 *)(DAT_00008b1c + param_2 * 4);
  *(uint *)(iVar2 + 0xd0) = param_2 * 0x10000 + (param_5 & 0xe00) + DAT_00008b10;
  *(uint *)(iVar2 + 0xc) = param_5;
  *(undefined1 *)(iVar1 + 0x53) = param_3;
  *(undefined4 *)(iVar1 + 0x40) = param_7;
  return;
}

