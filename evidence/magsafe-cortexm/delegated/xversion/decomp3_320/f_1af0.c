
void FUN_00001af0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined1 auStack_54 [32];
  undefined1 auStack_34 [32];
  
  FUN_000017d0(auStack_54,param_2,param_2);
  pcVar1 = DAT_00001b44;
  (*DAT_00001b44)(auStack_34,auStack_54,param_3);
  (*pcVar1)(param_1,auStack_34,param_4);
  (*pcVar1)(auStack_34,param_3,param_1);
  FUN_000017d0(auStack_54,param_2,auStack_34);
  (*pcVar1)(param_1 + 0x20,auStack_54,param_3 + 0x20);
  return;
}

