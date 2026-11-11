
undefined8 FUN_0000295c(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  undefined4 local_18;
  
  if (1 < param_1) {
    return CONCAT44(param_2,7);
  }
  local_20 = param_2;
  if (((param_1 == 1) && (*(char *)(DAT_00002a40 + 3) != '\0')) ||
     (iVar3 = DAT_00002a44 + param_1 * 0x1cc, *(char *)(iVar3 + 0x43) != '\0')) goto LAB_00002988;
  local_20 = 1;
  local_18 = param_4;
  FUN_0000a7d0();
  uVar2 = 0xb;
  if ((*(char *)(iVar3 + 0x31) == '\0') || (*(char *)(iVar3 + 0x1d) == '\0')) goto LAB_00002a3a;
  if (*(char *)(iVar3 + 0x2f) == '\0') {
    if ((param_2 != 5) && (*(int *)(iVar3 + 0x48) != 0)) goto LAB_00002988;
  }
  else if (param_2 != 5) {
LAB_00002988:
    return CONCAT44(local_20,0xf);
  }
  if ((*(char *)(iVar3 + 0x45) != '#') &&
     (((*(char *)(iVar3 + 0x45) != '\x0f' || (param_2 != 0)) && (param_2 != 5)))) goto LAB_00002a3a;
  if ((((param_2 != 5) && (1 < *(byte *)(iVar3 + 0x3e))) && (*(char *)(iVar3 + 0x1c9) != '\x01')) &&
     (*(char *)(iVar3 + 0x15) == '\0')) {
    if (*(char *)(iVar3 + 0x16) == '\x03') {
      uVar1 = FUN_00008778(param_1);
      local_18 = CONCAT22(local_18._2_2_,uVar1);
      if (*(char *)((int)&local_18 + (uint)*(byte *)(iVar3 + 0x1a)) == '\x03') goto LAB_00002a16;
    }
    if (*(char *)(iVar3 + 0x43) == '\0') {
      return 0x10000000e;
    }
  }
LAB_00002a16:
  *(char *)(iVar3 + 0x2e) = (char)param_2;
  *(undefined1 *)(iVar3 + 0x2f) = 1;
  *(undefined4 *)(iVar3 + 100) = param_4;
  if (param_3 != 0) {
    FUN_00000170(*(undefined4 *)(iVar3 + 0x6c),param_3,0x2c);
  }
  FUN_00002908(param_1,0x200);
  uVar2 = 0;
LAB_00002a3a:
  return CONCAT44(1,uVar2);
}

