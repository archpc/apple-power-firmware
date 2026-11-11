
void FUN_00012a70(void)

{
  FUN_00000b50();
  *DAT_00012a94 = (uint)*DAT_00012a90;
  *DAT_00012a98 = *DAT_00012a98 | 4;
  WaitForInterrupt();
  FUN_00000b58();
  return;
}

