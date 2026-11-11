
void FUN_0000b18c(int param_1,int param_2,code *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_000028e8();
  iVar1 = DAT_0000b25c;
  if (*(char *)(*(int *)(DAT_0000b25c + 0x58) + 0x21) != '\0') {
    FUN_00002e68(1);
  }
  *(undefined1 *)(iVar1 + 0x69) = 1;
  iVar3 = DAT_0000b264;
  iVar2 = DAT_0000b260;
  if (*(char *)(DAT_0000b260 + 0x3e) != '\x01') {
    *(undefined1 *)(DAT_0000b264 + 4) = 1;
  }
  if (*(char *)(iVar1 + 0x54) == '\0') {
    if (*(char *)(*(int *)(iVar1 + 0x58) + 0x20) != '\0') {
      if ((*(uint *)(param_2 + 4) & DAT_0000b24c + 0xe) == DAT_0000b24c) {
        FUN_0000a4e8(0);
        FUN_00006910();
      }
      else {
        if (*(char *)(iVar3 + 0x1c) == '\x01') {
          FUN_00006910();
          *(undefined1 *)(iVar3 + 0x1c) = 0;
        }
        FUN_0000a4e8(1);
      }
      *(undefined1 *)(iVar1 + 0x55) = 1;
      *(code **)(iVar3 + 0x54) = param_3;
      return;
    }
  }
  else {
    *(undefined1 *)(iVar1 + 0x54) = 0;
    *(undefined1 *)(iVar2 + param_1 * 0x1cc + 0x1bc) = 0;
  }
  (*param_3)(param_1);
  return;
}

