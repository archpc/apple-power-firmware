
void FUN_00009d38(void)

{
  int iVar1;
  
  if (*(int *)(DAT_00009db0 + 0x10) == 0) {
    *(undefined4 *)(DAT_00009db4 + 0x70) = DAT_00009db8;
    *DAT_00009d9c = 0x1000;
    FUN_00012bd8(0);
    *DAT_00009da0 = 0x1000;
    FUN_00012bd8(1);
    FUN_00012a48();
    iVar1 = DAT_00009dbc;
    if (*(char *)(DAT_00009dbc + 0x25) == '\0') {
      FUN_00012a48();
      *(undefined1 *)(iVar1 + 0x25) = 1;
    }
    *DAT_00009da4 = *DAT_00009da4 | 0x80000000;
    *DAT_00009da8 = (uint)*(ushort *)(iVar1 + 0x3a);
    *DAT_00009dac = *DAT_00009dac & 0xfffffff8 | 8;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000967c(0xf);
}

