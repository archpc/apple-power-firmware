
void FUN_00002a30(uint param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = DAT_00002a58;
  if ((param_1 != 0) && (param_1 < 8)) {
    puVar2 = (undefined4 *)(DAT_00002a58 + 0x268);
    for (uVar3 = param_1; uVar3 != 0; uVar3 = uVar3 - 1) {
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      *puVar2 = uVar4;
      puVar2 = puVar2 + 1;
    }
    *(char *)(iVar1 + 0x1d5) = (char)param_1;
  }
  return;
}

