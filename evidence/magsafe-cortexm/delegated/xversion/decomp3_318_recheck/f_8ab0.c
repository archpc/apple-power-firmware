
void FUN_00008ab0(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = *(int *)(DAT_00008b18 + param_1 * 4);
  *(uint *)(iVar1 + 0x154) = *(uint *)(iVar1 + 0x154) & 0xfffff9ff;
  *(undefined4 *)(iVar1 + 0x14c) = 0xe00;
  puVar2 = (uint *)(iVar1 + 0xe4);
  if (param_2 == 1) {
    *puVar2 = (DAT_00008b0c & *puVar2) + 0x4000;
    *(uint *)(iVar1 + 0x128) = (DAT_00008b10 & *(uint *)(iVar1 + 0x128)) + 0x200;
  }
  else if (param_2 == 0) {
    *puVar2 = DAT_00008b0c & *puVar2;
    *(uint *)(iVar1 + 0x128) = DAT_00008b10 & *(uint *)(iVar1 + 0x128);
  }
  *(undefined4 *)(iVar1 + 0x118) = DAT_00008b14;
  return;
}

