
void FUN_00001132(byte *param_1,undefined1 param_2,code *param_3,undefined4 param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if ((uint)*param_1 != (uint)param_1[1]) {
    *(undefined1 *)(*(int *)(param_1 + 4) + (uint)param_1[1]) = param_2;
    bVar1 = param_1[1];
    param_1[1] = bVar1 + 1;
    uVar4 = (byte)(bVar1 + 1) - 1;
    while (uVar4 != 0) {
      uVar5 = uVar4 - 1 >> 1;
      iVar3 = (*param_3)(*(undefined1 *)(*(int *)(param_1 + 4) + uVar4),
                         *(undefined1 *)(*(int *)(param_1 + 4) + uVar5),param_4);
      if (iVar3 == 0) {
        return;
      }
      iVar3 = *(int *)(param_1 + 4);
      uVar2 = *(undefined1 *)(iVar3 + uVar5);
      *(undefined1 *)(iVar3 + uVar5) = *(undefined1 *)(iVar3 + uVar4);
      *(undefined1 *)(*(int *)(param_1 + 4) + uVar4) = uVar2;
      uVar4 = uVar5;
    }
  }
  return;
}

