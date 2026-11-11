
void FUN_0000a824(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  uint uVar5;
  
  puVar3 = DAT_0000a86c;
  iVar2 = DAT_0000a868;
  if (param_1 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(DAT_0000a86c);
    *(undefined1 *)(iVar2 + 0xb) = 1;
    uVar4 = FUN_00001178(DAT_0000a864,0,DAT_0000a870,0);
    *puVar3 = uVar4;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  if (*(char *)(iVar2 + 0xc) == '\x01') {
    FUN_00002178();
    FUN_0000ba84();
    *(undefined1 *)(iVar2 + 0xc) = 0;
  }
  return;
}

