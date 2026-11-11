
void FUN_0000c4ec(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_40 [4];
  undefined1 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  undefined4 local_30 [7];
  
  iVar1 = DAT_0000c55c;
  iVar3 = 0;
  for (iVar2 = param_3; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)((int)local_30 + iVar3) = *(undefined4 *)(param_2 + iVar3);
    iVar3 = iVar3 + 4;
  }
  *(undefined1 *)(DAT_0000c55c + 0x1c9) = 1;
  local_34 = 0;
  local_3c = (undefined1)param_3;
  local_40[0] = 0;
  local_38 = 0;
  iVar2 = FUN_0000290c(param_1,0xc,local_40,DAT_0000c560);
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + DAT_0000c558) = 1;
  }
  else {
    *(undefined1 *)(iVar1 + DAT_0000c558) = 0;
    *(undefined1 *)(iVar1 + 0x1c9) = 0;
    *(undefined4 *)(DAT_0000c564 + param_1 * 0x30 + 0x2c) = 4;
    FUN_0000c3f8(param_1,4,1,0);
  }
  return;
}

