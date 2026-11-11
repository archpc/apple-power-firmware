
uint FUN_00000880(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar3 = param_1 >> 1 | param_1;
    uVar3 = uVar3 >> 2 | uVar3;
    uVar3 = uVar3 >> 4 | uVar3;
    uVar3 = uVar3 >> 8 | uVar3;
    uVar3 = ~(uVar3 >> 0x10 | uVar3);
    uVar3 = uVar3 - (uVar3 >> 1 & DAT_0000093c);
    uVar3 = (uVar3 & DAT_00000940) + (uVar3 >> 2 & DAT_00000940);
    uVar5 = DAT_00000948 * (uVar3 + (uVar3 >> 4) & DAT_00000944) >> 0x18;
    uVar3 = param_2 >> 1 | param_2;
    uVar3 = uVar3 >> 2 | uVar3;
    uVar3 = uVar3 >> 4 | uVar3;
    uVar3 = uVar3 >> 8 | uVar3;
    uVar3 = ~(uVar3 >> 0x10 | uVar3);
    uVar3 = uVar3 - (uVar3 >> 1 & DAT_0000093c);
    uVar3 = (uVar3 & DAT_00000940) + (uVar3 >> 2 & DAT_00000940);
    uVar3 = DAT_00000948 * (uVar3 + (uVar3 >> 4) & DAT_00000944) >> 0x18;
    uVar4 = uVar3 - uVar5;
    if ((uVar4 < 0x20) && (uVar1 = param_1, uVar4 != 0x1f)) {
      iVar2 = ~uVar3 + uVar5;
      uVar3 = param_1 >> (uVar4 + 1 & 0xff);
      param_1 = param_1 << (0x1f - uVar4 & 0xff);
      uVar1 = 0;
      do {
        uVar3 = uVar3 * 2 - ((int)param_1 >> 0x1f);
        uVar4 = (int)(~uVar3 + param_2) >> 0x1f;
        uVar3 = uVar3 - (uVar4 & param_2);
        param_1 = param_1 << 1 | uVar1;
        uVar1 = uVar4 & 1;
        bVar6 = iVar2 != -1;
        iVar2 = iVar2 + 1;
      } while (bVar6);
      uVar1 = uVar1 + param_1 * 2;
    }
  }
  return uVar1;
}

