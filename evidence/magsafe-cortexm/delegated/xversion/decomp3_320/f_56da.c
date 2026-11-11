
void FUN_000056da(int param_1)

{
  int unaff_r5;
  char in_NG;
  
  if ((in_NG != '\0') && (*(char *)(param_1 + 0x1a1) != '\0')) {
    *(uint *)(unaff_r5 + 0xe8) =
         (uint)*(ushort *)(unaff_r5 + 0xe8) + (uint)*(byte *)(param_1 + 0x172) * 0x10000 + 0x1000000
    ;
    FUN_00007260();
    return;
  }
  FUN_00003258();
  return;
}

