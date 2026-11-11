
void FUN_0000c5f8(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  undefined1 *puVar1;
  
  (*param_4)(param_1);
  FUN_0000ca08(param_1,0x99);
  FUN_0000ca08(param_2,0x99);
  puVar1 = DAT_0000c63c;
  *DAT_0000c63c = (char)param_2;
  FUN_00000170(puVar1 + 4,param_3,0x3c);
  FUN_0000c4ec(param_2,param_3 + 8,*(undefined1 *)(param_3 + 1));
  return;
}

