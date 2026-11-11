
void switchD_00004218::caseD_7(void)

{
  int iVar1;
  int unaff_r4;
  int *piVar2;
  
  iVar1 = FUN_0000639c();
  if (iVar1 != 0) {
    piVar2 = (int *)(DAT_00004768 + unaff_r4 * 0xf0);
    iVar1 = DAT_0000476c + unaff_r4 * 0x1cc;
    (**(code **)(*(int *)(iVar1 + 0x60) + 0x18))();
    *(undefined1 *)(iVar1 + 0x28) = 0;
    *(undefined1 *)(*piVar2 + 2) = 3;
    FUN_000064d0();
    return;
  }
  FUN_00003140();
  return;
}

