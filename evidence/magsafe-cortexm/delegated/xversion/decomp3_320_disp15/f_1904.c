
uint FUN_00001904(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  byte local_94 [28];
  uint local_78;
  byte local_74 [28];
  uint local_58;
  byte local_54 [32];
  byte local_34 [32];
  
  pcVar1 = DAT_00001a38;
  (*DAT_00001a38)(local_34,param_3,0x20);
  (*pcVar1)(local_54,param_4,0x20);
  (*pcVar1)(local_74,param_2,0x20);
  FUN_000001a0(local_94,0,0x20);
  uVar2 = FUN_000017b0(param_3);
  if (uVar2 == 0) {
    while (iVar3 = FUN_000016fc(local_34,local_54), iVar3 != 0) {
      if ((local_34[0] & 1) == 0) {
        FUN_00001a3c(local_34);
LAB_00001966:
        if ((local_74[0] & 1) == 0) {
          FUN_00001a3c(local_74);
        }
        else {
          iVar3 = FUN_00001a5e(local_74,param_4);
          FUN_00001a3c(local_74);
          if (iVar3 != 0) {
            local_58 = local_58 | 0x80000000;
          }
        }
      }
      else {
        if ((local_54[0] & 1) == 0) {
          FUN_00001a3c(local_54);
        }
        else {
          if (0 < iVar3) {
            FUN_00001730(local_34,local_54);
            FUN_00001a3c(local_34);
            iVar3 = FUN_00001730(local_74,local_94);
            if (iVar3 != 0) {
              FUN_00001a5e(local_74,param_4);
            }
            goto LAB_00001966;
          }
          FUN_00001730(local_54,local_34);
          FUN_00001a3c(local_54);
          iVar3 = FUN_00001730(local_94,local_74);
          if (iVar3 != 0) {
            FUN_00001a5e(local_94,param_4);
          }
        }
        if ((local_94[0] & 1) == 0) {
          FUN_00001a3c(local_94);
        }
        else {
          iVar3 = FUN_00001a5e(local_94,param_4);
          FUN_00001a3c(local_94);
          if (iVar3 != 0) {
            local_78 = local_78 | 0x80000000;
          }
        }
      }
    }
    FUN_00000170(param_1,local_74,0x20);
  }
  return uVar2 ^ 1;
}

