
void FUN_00001bc4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_74 [32];
  undefined1 auStack_54 [32];
  undefined1 auStack_34 [32];
  
  iVar1 = FUN_00001c44(param_2);
  iVar2 = param_3;
  if ((iVar1 == 0) && (iVar1 = FUN_00001c44(param_3), iVar2 = param_2, iVar1 == 0)) {
    FUN_00001b50(auStack_34,param_3 + 0x20,param_2 + 0x20);
    FUN_00001b50(auStack_54,param_3,param_2);
    iVar2 = FUN_0000197c(auStack_74,auStack_34,auStack_54,DAT_00001c40);
    if (iVar2 == 0) {
      FUN_000001a2(param_1,0,0x40);
    }
    else {
      FUN_00001b6c(param_1,auStack_74,param_2,param_3);
    }
  }
  else {
    FUN_00000170(param_1,iVar2,0x40);
  }
  return;
}

