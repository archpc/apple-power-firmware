
bool FUN_000017b0(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  do {
    if (uVar1 == 7) {
      uVar1 = 8;
      break;
    }
    iVar2 = *param_1;
    param_1 = param_1 + 1;
    uVar1 = uVar1 + 1;
  } while (iVar2 == 0);
  return 7 < uVar1;
}

