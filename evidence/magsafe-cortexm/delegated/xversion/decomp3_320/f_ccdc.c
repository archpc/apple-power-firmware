
void FUN_0000ccdc(byte *param_1,uint param_2,undefined2 *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = DAT_0000cd08;
  uVar2 = 0x10 - (*DAT_0000cd08 & 0x1f) & 0xff;
  uVar3 = uVar2;
  if (param_2 <= uVar2) {
    uVar2 = param_2;
    uVar3 = param_2;
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar1[0xe] = (uint)*param_1;
    param_1 = param_1 + 1;
  }
  *param_3 = (short)uVar3;
  return;
}

