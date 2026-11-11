
void FUN_00001b48(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_74 [32];
  undefined1 auStack_54 [32];
  undefined1 auStack_34 [32];
  
  iVar1 = FUN_00001bc8(param_2);
  iVar2 = param_3;
  if ((iVar1 == 0) && (iVar1 = FUN_00001bc8(param_3), iVar2 = param_2, iVar1 == 0)) {
    FUN_00001ad4(auStack_34,param_3 + 0x20,param_2 + 0x20);
    FUN_00001ad4(auStack_54,param_3,param_2);
    iVar2 = FUN_00001904(auStack_74,auStack_34,auStack_54,DAT_00001bc4);
    if (iVar2 == 0) {
      FUN_000001a0(param_1,0,0x40);
    }
    else {
      FUN_00001af0(param_1,auStack_74,param_2,param_3);
    }
  }
  else {
    FUN_00000170(param_1,iVar2,0x40);
  }
  return;
}

