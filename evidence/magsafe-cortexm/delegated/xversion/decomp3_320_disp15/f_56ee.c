
void FUN_000056ee(int param_1,int param_2,int param_3,int param_4)

{
  int unaff_r5;
  int iStack00000000;
  
  *(uint *)(unaff_r5 + param_2) = param_3 + (uint)*(byte *)(param_1 + param_4) * 0x10000 + 0x1000000
  ;
  iStack00000000 = unaff_r5 + 0xe8;
  FUN_00007260();
  return;
}

