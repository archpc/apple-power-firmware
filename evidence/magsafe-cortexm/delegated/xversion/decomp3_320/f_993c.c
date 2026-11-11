
void FUN_0000993c(void)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = DAT_0000999c;
  if (*(int *)(DAT_0000999c + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0000975c(0xe);
  }
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_0000991c();
  piVar4 = DAT_00009994;
  cVar1 = *(char *)(iVar5 + 0x60);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  bVar3 = cVar1 - 1;
  if (99 < bVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_0000975c(4);
  }
  while (-1 < *piVar4 << 0x1b) {
    piVar4[0xe] = 0x55;
  }
  FUN_000099a0((int)(char)bVar3);
  if (cVar1 == '2') {
    FUN_00000f54(iVar5 + 0x38);
  }
  *DAT_00009998 = *DAT_00009998;
  return;
}

