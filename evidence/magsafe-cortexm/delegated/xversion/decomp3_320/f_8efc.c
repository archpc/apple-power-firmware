
uint FUN_00008efc(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  FUN_00000b70();
  if ((param_1 != (uint *)0x0) && (*param_1 != 0)) {
    for (uVar2 = 0; uVar2 != 0x20; uVar2 = uVar2 + 1) {
      uVar1 = 1 << (uVar2 & 0xff);
      if ((uVar1 & *param_1) != 0) {
        *param_1 = *param_1 & ~uVar1;
        goto LAB_00008f2e;
      }
    }
  }
  uVar2 = 0x20;
LAB_00008f2e:
  FUN_00000b78();
  return uVar2 & 0xff;
}

