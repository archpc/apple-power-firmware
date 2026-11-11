
void FUN_0000cd78(undefined1 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_24 [8];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  
  uVar1 = DAT_0000cdb0;
  local_1c[0] = param_2;
  local_18[0] = param_1;
  FUN_0000131c(DAT_0000cdb0,auStack_24);
  iVar2 = DAT_0000cdb4;
  *(undefined1 *)(DAT_0000cdb4 + 0x10) = 1;
  *(undefined1 **)(iVar2 + 0xc) = local_18;
  *(undefined2 *)(iVar2 + 8) = 1;
  *(undefined1 **)(iVar2 + 4) = local_1c;
  software_interrupt(0x41);
  FUN_00001360(uVar1,auStack_24);
  return;
}

