
void FUN_00006b70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_00006bc8;
  iVar4 = DAT_00006bc8 + param_1 * 0x88;
  bVar1 = *(byte *)(iVar4 + 0x74);
  if (*(char *)(iVar4 + 0x73) == '\x01') {
    *(undefined1 *)(iVar4 + 0x73) = 0;
    FUN_0000c93c(param_1,4,5,param_4,param_2);
    if (bVar1 < 4) {
      iVar3 = iVar4 + (uint)bVar1 * 3;
      *(byte *)(iVar3 + 4) = *(char *)(iVar3 + 4) + 1U & 7;
    }
    *(byte *)(iVar4 + 0x79) = bVar1;
    FUN_00008b44(param_1);
    (**(code **)(iVar2 + param_1 * 0x88))(param_1,param_2);
  }
  return;
}

