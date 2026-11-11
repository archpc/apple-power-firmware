
void FUN_000012d0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar4 = DAT_0000132c;
  iVar7 = DAT_0000132c + 0x110;
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar5 = *(int *)(DAT_0000132c + 0x114);
  uVar6 = 0;
  do {
    if (*(byte *)(DAT_0000132c + 0x111) == uVar6) {
LAB_00001320:
      *param_1 = -1;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar8 & 1) == 1);
      }
      return;
    }
    if (*(char *)(iVar5 + uVar6) == *param_1) {
      bVar3 = *(byte *)(DAT_0000132c + 0x111) - 1;
      *(byte *)(DAT_0000132c + 0x111) = bVar3;
      uVar1 = *(undefined1 *)(iVar5 + uVar6);
      *(undefined1 *)(iVar5 + uVar6) = *(undefined1 *)(iVar5 + (uint)bVar3);
      *(undefined1 *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = uVar1;
      FUN_000010cc(iVar7,uVar6,DAT_00001330,0,param_4);
      *(char *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = *param_1;
      FUN_0000126c();
      goto LAB_00001320;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}

