
void FUN_0000a908(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  uint uVar5;
  
  puVar3 = DAT_0000a950;
  iVar2 = DAT_0000a94c;
  if (param_1 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012d0(DAT_0000a950);
    *(undefined1 *)(iVar2 + 0x12) = 1;
    uVar4 = FUN_000011a0(DAT_0000a948,0,DAT_0000a954,0);
    *puVar3 = uVar4;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  if (*(char *)(iVar2 + 0x13) == '\x01') {
    FUN_00002114();
    FUN_0000bba4();
    *(undefined1 *)(iVar2 + 0x13) = 0;
  }
  return;
}

