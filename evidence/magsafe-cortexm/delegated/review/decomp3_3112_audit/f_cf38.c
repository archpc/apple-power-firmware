
undefined4 FUN_0000cf38(byte *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_28;
  uint local_1c;
  uint local_18;
  
  piVar1 = DAT_0000d03c;
  local_28 = 0;
  FUN_000001a2(DAT_0000d03c,0,0x80);
  iVar2 = (*pcRam000003f0)(piVar1,0x10000,0x80);
  if (iVar2 < 0) {
    uVar3 = 0xf;
  }
  else {
    uVar3 = 1;
    if (*piVar1 == DAT_0000d030) {
      local_18 = piVar1[1];
      (*pcRam000003f0)(&local_1c,&DAT_00010098,4);
      *param_1 = (byte)(local_18 >> 0x1f);
      uVar3 = DAT_0000d044;
      iVar2 = DAT_0000d040;
      if ((((int)local_18 < 0) || (*(char *)(DAT_0000d040 + 0x66) == '\x01')) ||
         (DAT_0000d038 <= (local_18 & DAT_0000d034))) {
        FUN_00001554(DAT_0000d044);
        FUN_0000d320(uVar3,0x10000,0xa0);
        if ((*param_1 == 0) || ((local_1c & 1) != 0)) {
          if ((local_1c & 1) != 0) {
            uVar3 = FUN_000007be(iVar2 + 0x34,0x11);
            FUN_000016ac(DAT_0000d044,iVar2 + 0x34,uVar3);
          }
          FUN_000016e4(DAT_0000d044);
          iVar5 = 0x60;
          (*pcRam000003f0)(piVar1,&DAT_000100a0,0x60);
          iVar2 = FUN_0000d2fc(piVar1 + 0x10);
          if (iVar2 == 0) {
            uVar3 = 3;
          }
          else {
            for (iVar2 = 0x5c; uVar3 = local_28, iVar2 != 0x3c; iVar2 = iVar2 + -4) {
              uVar4 = *(uint *)((int)piVar1 + iVar2);
              *(uint *)((int)piVar1 + iVar5) =
                   uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                   uVar4 >> 0x18;
              iVar5 = iVar5 + 4;
            }
          }
        }
        else {
          uVar3 = 6;
        }
      }
      else {
        uVar3 = 2;
      }
    }
  }
  return uVar3;
}

