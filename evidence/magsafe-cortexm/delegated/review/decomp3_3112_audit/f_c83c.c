
void FUN_0000c83c(int param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  
  iVar3 = *(int *)(param_1 + 0xc);
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *(undefined1 *)(DAT_0000c874 + iVar3) = 0xff;
  uVar1 = *(ushort *)(DAT_0000c878 + iVar3 * 2);
  *(short *)(DAT_0000c878 + iVar3 * 2) = (short)DAT_0000c870;
  pcVar4 = *(code **)(DAT_0000c87c + iVar3 * 4);
  *(undefined4 *)(DAT_0000c87c + iVar3 * 4) = 0;
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(uVar1 >> 8,(char)uVar1);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar5 & 1) == 1);
  }
  return;
}

