
void FUN_00005c8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(DAT_00005d34 + param_1 * 0xf0);
  if (*pcVar3 == '\x01') {
    if (pcVar3[2] == '\x0f') {
      iVar1 = DAT_00005d34 + param_1 * 0xf0;
      *(undefined2 *)(iVar1 + 0xb0) = 0;
      *(short *)(iVar1 + 0xaa) = (short)DAT_00005d30;
      *(undefined1 *)(iVar1 + 0xa9) = 0;
      FUN_00002db8(param_1,0x800);
      iVar1 = DAT_00005d38 + param_1 * 0x1cc;
      (**(code **)(*(int *)(iVar1 + 0x60) + 0x54))(param_1,pcVar3,DAT_00005d3c);
      FUN_000030f0(param_1,9,0x14);
      FUN_00002db8(param_1,0x100);
      *(undefined1 *)(iVar1 + 0x45) = 0x24;
      return;
    }
    if ((int)((uint)(byte)pcVar3[5] << 0x18) < 0) {
      pcVar2 = *(code **)(*(int *)(DAT_00005d38 + param_1 * 0x1cc + 0x60) + 0x58);
      (*pcVar2)(param_1,pcVar3,DAT_00005d40,pcVar2,param_4);
      return;
    }
    iVar1 = *(int *)(DAT_00005d38 + param_1 * 0x1cc + 0x60);
    if (pcVar3[1] == '\0') {
      pcVar2 = *(code **)(iVar1 + 0x60);
    }
    else {
      pcVar2 = *(code **)(iVar1 + 0x5c);
    }
    (*pcVar2)(param_1,pcVar3);
  }
  return;
}

