
undefined8 FUN_00007288(uint param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (1 < param_1) {
    return CONCAT44(param_2,2);
  }
  uVar2 = FUN_00000b70();
  pcVar1 = DAT_000072f4;
  (*DAT_000072f4)(param_1);
  (*pcVar1)(param_1,4);
  (*pcVar1)(param_1,7);
  FUN_00008c8c(param_1);
  iVar3 = DAT_000072f8 + param_1 * 0x88;
  *(undefined1 *)(iVar3 + 0x73) = 0;
  *(undefined4 *)(iVar3 + 0x80) = 0;
  *(undefined1 *)(iVar3 + 0x84) = 0;
  FUN_00000b78(uVar2);
  *(undefined1 *)(iVar3 + 0x74) = 5;
  FUN_0000c908(param_1,7,0x14,DAT_000072fc);
  *(undefined1 *)(iVar3 + 0x73) = 1;
  uVar2 = FUN_00008cc8(param_1);
  return CONCAT44(param_2,uVar2);
}

