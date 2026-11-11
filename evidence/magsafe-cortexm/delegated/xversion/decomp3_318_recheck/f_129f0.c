
void FUN_000129f0(void)

{
  FUN_00000b50();
  *DAT_00012a14 = (uint)*DAT_00012a10;
  *DAT_00012a18 = *DAT_00012a18 | 4;
  WaitForInterrupt();
  FUN_00000b58();
  return;
}

