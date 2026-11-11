
void FUN_0000cf08(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_24 [8];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  
  iVar2 = DAT_0000cf40 + 0x30;
  local_1c[0] = param_2;
  local_18[0] = param_1;
  FUN_00001334(iVar2,auStack_24);
  iVar1 = DAT_0000cf44;
  *(undefined1 *)(DAT_0000cf44 + 0x10) = 1;
  *(undefined1 **)(iVar1 + 0xc) = local_18;
  *(undefined2 *)(iVar1 + 8) = 1;
  *(undefined1 **)(iVar1 + 4) = local_1c;
  software_interrupt(0x41);
  FUN_00001378(iVar2,auStack_24);
  return;
}

