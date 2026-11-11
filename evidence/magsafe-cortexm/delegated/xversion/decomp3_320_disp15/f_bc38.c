
void FUN_0000bc38(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0000bc68;
  iVar2 = DAT_0000bc68 + param_1 * 0x20;
  FUN_000001a0(iVar2,0,0x20);
  *(char *)(iVar1 + param_1 * 0x20) = (char)param_1;
  *(undefined4 *)(iVar2 + 8) = 1;
  *(undefined4 *)(iVar2 + 4) = param_2;
  *(short *)(iVar2 + 0x1c) = (short)DAT_0000bc64;
  *(undefined4 *)(iVar2 + 0x10) = param_2;
  *(char *)(iVar2 + 0xc) = (char)param_1;
  return;
}

