
void FUN_00001a8c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  for (iVar1 = 0; iVar1 != 0x20; iVar1 = iVar1 + 4) {
    uVar3 = *(uint *)(param_2 + iVar1);
    uVar4 = uVar3 + uVar2 + *(int *)(param_3 + iVar1);
    *(uint *)(param_1 + iVar1) = uVar4;
    if (uVar4 != uVar3) {
      uVar2 = (uint)(uVar4 < uVar3);
    }
  }
  if ((uVar2 != 0) || (iVar1 = FUN_000016fc(param_1,DAT_00001ad0,param_3,0,param_4), 0 < iVar1)) {
    FUN_00001730(param_1,DAT_00001ad0);
  }
  return;
}

