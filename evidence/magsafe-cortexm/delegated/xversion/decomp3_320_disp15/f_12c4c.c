
void FUN_00012c4c(void)

{
  FUN_00000b70();
  *DAT_00012c70 = (uint)*DAT_00012c6c;
  *DAT_00012c74 = *DAT_00012c74 | 4;
  WaitForInterrupt();
  FUN_00000b78();
  return;
}

