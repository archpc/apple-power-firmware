
void FUN_00001c60(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_94 [32];
  undefined1 auStack_74 [32];
  undefined1 auStack_54 [32];
  undefined1 auStack_34 [32];
  
  iVar2 = FUN_00001c44(param_2);
  if (iVar2 == 0) {
    FUN_0000183c(auStack_34,param_2,param_2);
    pcVar1 = DAT_00001ce4;
    (*DAT_00001ce4)(auStack_54,auStack_34,auStack_34);
    (*pcVar1)(auStack_74,auStack_34,auStack_54);
    FUN_00001b50(auStack_34,auStack_74,DAT_00001ce8);
    (*pcVar1)(auStack_54,param_2 + 0x20,param_2 + 0x20);
    iVar2 = FUN_0000197c(auStack_94,auStack_34,auStack_54,DAT_00001cec);
    if (iVar2 == 0) {
      FUN_000001a2(param_1,0,0x40);
    }
    else {
      FUN_00001b6c(param_1,auStack_94,param_2,param_2);
    }
  }
  else {
    FUN_00000170(param_1,param_2,0x40);
  }
  return;
}

