
void FUN_00002a60(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = DAT_00002a88;
  if (param_1 - 1U < 7) {
    puVar2 = (undefined4 *)(DAT_00002a88 + 0x268);
    for (iVar3 = param_1; iVar3 != 0; iVar3 = iVar3 + -1) {
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      *puVar2 = uVar4;
      puVar2 = puVar2 + 1;
    }
    *(char *)(iVar1 + 0x1d5) = (char)param_1;
  }
  return;
}

