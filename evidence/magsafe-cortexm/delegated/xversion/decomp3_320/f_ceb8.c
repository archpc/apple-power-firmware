
int FUN_0000ceb8(void)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_24 [8];
  char local_1c [4];
  undefined1 local_18 [4];
  
  local_18[0] = 0;
  local_1c[0] = 'd';
  iVar2 = DAT_0000cf00 + 0x30;
  FUN_00001334(iVar2,auStack_24);
  uVar1 = DAT_0000cf04;
  *(undefined1 *)(DAT_0000cf04 + 0x10) = 1;
  *(undefined1 **)(uVar1 + 0xc) = local_18;
  *(undefined2 *)(uVar1 + 8) = 1;
  *(char **)(uVar1 + 4) = local_1c;
  software_interrupt(0x40);
  if ((uVar1 & 0xff) == 0) {
    FUN_00001378(iVar2,auStack_24);
    return (int)local_1c[0];
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000975c(3);
}

