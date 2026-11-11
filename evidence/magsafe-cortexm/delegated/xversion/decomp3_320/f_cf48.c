
undefined4 FUN_0000cf48(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_194 [4];
  undefined4 local_190;
  int local_18c;
  int local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_98;
  int local_94 [3];
  undefined4 local_88;
  
  iVar3 = 4;
  iVar2 = DAT_0000cfc4;
  while( true ) {
    if (iVar3 == 0) {
      return 0x85;
    }
    (*pcRam000003f0)(local_94,iVar2,0x80);
    iVar1 = FUN_0000cfc8(local_94);
    if (iVar1 == 0) break;
    if (local_88._3_1_ == ' ') {
      FUN_000001a0(local_194,0);
      local_194[0] = 4;
      local_18c = iVar2 + 0x80;
      local_180 = 1;
      local_184 = 0x10000;
      local_190 = local_88;
      local_188 = local_94[0];
      local_98 = FUN_0000140c(local_194,0xfc);
      FUN_00009eec(0x1000,local_194,0x100);
      return 0;
    }
    iVar2 = iVar2 + local_94[0] + 0x80;
    iVar3 = iVar3 + -1;
  }
  return 0x85;
}

