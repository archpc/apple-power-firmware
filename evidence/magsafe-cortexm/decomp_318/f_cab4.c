
void FUN_0000cab4(byte *param_1,uint param_2,ushort *param_3)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0000cae0;
  uVar2 = 0x10 - (*DAT_0000cae0 & 0x1f);
  if ((uVar2 & 0xff) <= param_2) {
    param_2 = uVar2;
  }
  for (uVar2 = param_2 & 0xff; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar1[0xe] = (uint)*param_1;
    param_1 = param_1 + 1;
  }
  *param_3 = (ushort)param_2 & 0xff;
  return;
}

