
undefined4 FUN_0000197c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 local_98;
  byte local_94 [28];
  uint local_78;
  byte local_74 [28];
  uint local_58;
  byte local_54 [32];
  byte local_34 [32];
  
  pcVar1 = DAT_00001ab4;
  (*DAT_00001ab4)(local_34,param_3,0x20);
  (*pcVar1)(local_54,param_4,0x20);
  (*pcVar1)(local_74,param_2,0x20);
  local_98 = 0;
  FUN_000001a2(local_94,0,0x20);
  iVar2 = FUN_00001822(param_3);
  if (iVar2 == 0) {
    local_98 = 1;
    while (iVar2 = FUN_0000176c(local_34,local_54), iVar2 != 0) {
      if ((local_34[0] & 1) == 0) {
        FUN_00001ab8(local_34);
LAB_000019de:
        if ((local_74[0] & 1) == 0) {
          FUN_00001ab8(local_74);
        }
        else {
          iVar2 = FUN_00001ada(local_74,param_4);
          FUN_00001ab8(local_74);
          if (iVar2 != 0) {
            local_58 = local_58 | 0x80000000;
          }
        }
      }
      else {
        if ((local_54[0] & 1) == 0) {
          FUN_00001ab8(local_54);
        }
        else {
          iVar2 = FUN_0000176c(local_34,local_54);
          if (0 < iVar2) {
            FUN_000017a0(local_34,local_54);
            FUN_00001ab8(local_34);
            iVar2 = FUN_000017a0(local_74,local_94);
            if (iVar2 != 0) {
              FUN_00001ada(local_74,param_4);
            }
            goto LAB_000019de;
          }
          FUN_000017a0(local_54,local_34);
          FUN_00001ab8(local_54);
          iVar2 = FUN_000017a0(local_94,local_74);
          if (iVar2 != 0) {
            FUN_00001ada(local_94,param_4);
          }
        }
        if ((local_94[0] & 1) == 0) {
          FUN_00001ab8(local_94);
        }
        else {
          iVar2 = FUN_00001ada(local_94,param_4);
          FUN_00001ab8(local_94);
          if (iVar2 != 0) {
            local_78 = local_78 | 0x80000000;
          }
        }
      }
    }
    FUN_00000170(param_1,local_74,0x20);
  }
  return local_98;
}

