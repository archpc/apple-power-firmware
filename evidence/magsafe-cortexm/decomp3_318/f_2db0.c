
void FUN_00002db0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = DAT_00002e24;
  if (((*(char *)(DAT_00002e24 + 0x1ec) != '\0') && (*(char *)(DAT_00002e24 + 0x1e1) == '\x01')) &&
     (1 < *(byte *)(DAT_00002e24 + DAT_00002e18))) {
    *(char *)(DAT_00002e24 + 0x340) = (char)param_1;
    cVar1 = *(char *)(iVar2 + DAT_00002e1c);
    if (param_1 == 0) {
      if ((cVar1 != '\x02') && (*(char *)(iVar2 + DAT_00002e20) == '#')) {
        FUN_0000c838(1,0xb);
        FUN_000078bc(1,2);
      }
    }
    else if (cVar1 != '\x01') {
      FUN_000078bc(1,1);
      FUN_0000c82c(1,0xb,5);
      return;
    }
  }
  return;
}

