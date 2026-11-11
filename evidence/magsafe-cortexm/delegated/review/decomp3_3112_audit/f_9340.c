
void FUN_00009340(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    FUN_000091a8();
    *DAT_00009388 = *DAT_00009388 | 8;
    uVar2 = *DAT_0000938c;
    puVar1 = DAT_0000938c;
  }
  else {
    if (param_1 == 1) {
      FUN_000091a8();
      *DAT_00009388 = *DAT_00009388 | 8;
      uVar2 = *DAT_0000938c | 8;
      puVar1 = DAT_0000938c;
      goto LAB_00009384;
    }
    if (param_1 != 2) {
      return;
    }
    FUN_0000927c();
    uVar2 = *DAT_00009388;
    puVar1 = DAT_00009388;
  }
  uVar2 = uVar2 & 0xfffffff7;
LAB_00009384:
  *puVar1 = uVar2;
  return;
}

