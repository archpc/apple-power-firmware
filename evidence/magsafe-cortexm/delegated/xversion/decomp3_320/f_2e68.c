
void FUN_00002e68(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = DAT_00002edc;
  if (((*(char *)(DAT_00002edc + 0x1ec) != '\0') && (*(char *)(DAT_00002edc + 0x1e1) == '\x01')) &&
     (1 < *(byte *)(DAT_00002edc + DAT_00002ed0))) {
    *(char *)(DAT_00002edc + 0x340) = (char)param_1;
    cVar1 = *(char *)(iVar2 + DAT_00002ed4);
    if (param_1 == 0) {
      if ((cVar1 != '\x02') && (*(char *)(iVar2 + DAT_00002ed8) == '#')) {
        FUN_0000ca08(1,0xb);
        FUN_00007a14(1,2);
      }
    }
    else if (cVar1 != '\x01') {
      FUN_00007a14(1,1);
      FUN_0000c9fc(1,0xb,5);
      return;
    }
  }
  return;
}

