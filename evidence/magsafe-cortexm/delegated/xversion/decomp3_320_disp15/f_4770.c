
void FUN_00004770(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = DAT_00004828 + param_1 * 0xf0;
  cVar1 = *(char *)(iVar3 + 0xe3);
  if ((param_2 == 2) && (cVar1 == '\v')) {
    (**(code **)(*(int *)(DAT_0000482c + param_1 * 0x1cc + 0x60) + 0x4c))(param_1,DAT_00004830);
    return;
  }
  if (2 < param_2 - 4U) {
    if (param_2 == 10) {
      cVar1 = *(char *)(iVar3 + 0x80);
      *(char *)(iVar3 + 0xc2) = cVar1;
      if (cVar1 == '\x01') goto LAB_000047e6;
      FUN_00006ec8(param_1,0,cVar1);
    }
    else if (param_2 == 3) {
      if (*(char *)(iVar3 + 0xc2) == '\x03') {
        if (cVar1 != '\v') {
          return;
        }
        if (*(char *)(DAT_0000482c + param_1 * 0x1cc + 0x28) == '\x01') {
          uVar2 = 0x19;
        }
        else {
          uVar2 = 0x18;
        }
      }
      else {
        if (cVar1 == '\v') {
          uVar2 = 0xf;
        }
        else {
          uVar2 = 0xe;
        }
        (*(code *)**(undefined4 **)(DAT_0000482c + param_1 * 0x1cc + 0x60))
                  (param_1,uVar2,iVar3 + 0xc2);
        uVar2 = 0x23;
      }
      FUN_00003258(param_1,uVar2);
      return;
    }
    return;
  }
  if (cVar1 != '\x13') {
    FUN_00005b5c(param_1);
    return;
  }
LAB_000047e6:
  FUN_00003140(param_1);
  return;
}

