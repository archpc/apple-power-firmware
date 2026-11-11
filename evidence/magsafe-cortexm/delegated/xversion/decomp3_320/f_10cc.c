
void FUN_000010cc(int param_1,uint param_2,code *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = param_2;
  while( true ) {
    uVar2 = (uint)*(byte *)(param_1 + 1);
    uVar7 = uVar4 * 2 + 2;
    uVar5 = uVar4 * 2 + 1;
    uVar6 = uVar4;
    if (uVar5 < uVar2) {
      iVar3 = (*param_3)(*(undefined1 *)(*(int *)(param_1 + 4) + uVar5),
                         *(undefined1 *)(*(int *)(param_1 + 4) + uVar4),param_4,param_3,param_2);
      uVar6 = uVar5;
      if (iVar3 == 0) {
        uVar6 = uVar4;
      }
      uVar2 = (uint)*(byte *)(param_1 + 1);
    }
    uVar5 = uVar6;
    if ((uVar7 < uVar2) &&
       (iVar3 = (*param_3)(*(undefined1 *)(*(int *)(param_1 + 4) + uVar7),
                           *(undefined1 *)(*(int *)(param_1 + 4) + uVar6),param_4), uVar5 = uVar7,
       iVar3 == 0)) {
      uVar5 = uVar6;
    }
    if (uVar5 == uVar4) break;
    iVar3 = *(int *)(param_1 + 4);
    uVar1 = *(undefined1 *)(iVar3 + uVar5);
    *(undefined1 *)(iVar3 + uVar5) = *(undefined1 *)(iVar3 + uVar4);
    *(undefined1 *)(*(int *)(param_1 + 4) + uVar4) = uVar1;
    uVar4 = uVar5;
  }
  return;
}

