
int FUN_0000be2c(int param_1,uint param_2)

{
  ushort *puVar1;
  int iVar2;
  
  puVar1 = (ushort *)(param_1 + 0x1c);
  for (iVar2 = 0; *(int *)(param_1 + 8) != iVar2; iVar2 = iVar2 + 1) {
    if (*puVar1 == param_2) goto LAB_0000be46;
    puVar1 = puVar1 + 1;
  }
  iVar2 = 0xff;
LAB_0000be46:
  return (int)(char)iVar2;
}

