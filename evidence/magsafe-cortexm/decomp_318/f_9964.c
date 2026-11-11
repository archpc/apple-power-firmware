
void FUN_00009964(void)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = DAT_000099c4;
  if (*(int *)(DAT_000099c4 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0000967c(0xe);
  }
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009944();
  piVar4 = DAT_000099bc;
  cVar1 = *(char *)(iVar5 + 0x40);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  bVar3 = cVar1 - 1;
  if (99 < bVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_0000967c(4);
  }
  while (-1 < *piVar4 << 0x1b) {
    piVar4[0xe] = 0x55;
  }
  FUN_000099c8((int)(char)bVar3);
  if (cVar1 == '2') {
    FUN_00000f28(iVar5 + 0x58);
  }
  *DAT_000099c0 = *DAT_000099c0;
  return;
}

