
undefined8
switchD_0000267a::caseD_1
          (byte param_1,uint param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
          undefined1 param_7)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_r4;
  uint uVar3;
  int unaff_r6;
  bool in_ZR;
  bool in_CY;
  
  if ((!in_CY || in_ZR) && (uVar3 = (param_2 & 0x7f) * 5, uVar3 < 0x1f5)) {
    iVar1 = FUN_0000089c((uint)param_1 * DAT_00002be4,param_4 * param_3);
    iVar2 = FUN_00000964(iVar1,5);
    if (uVar3 < (uint)(iVar1 - iVar2) || uVar3 - (iVar1 - iVar2) == 0) {
      *(undefined1 *)(unaff_r6 + 0x177) = param_7;
      unaff_r4 = 0;
    }
  }
  return CONCAT44(param_5,unaff_r4);
}

