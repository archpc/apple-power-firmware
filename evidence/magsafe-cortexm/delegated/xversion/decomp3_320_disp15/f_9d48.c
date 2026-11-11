
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00009d48(void)

{
  int iVar1;
  
  if (*(int *)(_LAB_00009dc0 + 0x10) == 0) {
    *(undefined4 *)(_LAB_00009dc4 + 0x70) = _LAB_00009dc8;
    *DAT_00009dac = 0x1000;
    FUN_00012e34(0);
    *DAT_00009db0 = 0x1000;
    FUN_00012e34(1);
    FUN_00012ca4();
    iVar1 = _LAB_00009dcc;
    if (*(char *)(_LAB_00009dcc + 0x2d) == '\0') {
      FUN_00012ca4();
      *(undefined1 *)(iVar1 + 0x2d) = 1;
    }
    *DAT_00009db4 = *DAT_00009db4 | 0x80000000;
    *DAT_00009db8 = (uint)*(ushort *)(iVar1 + 0x38);
    *_LAB_00009dbc = *_LAB_00009dbc & 0xfffffff8 | 8;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000975c(0xf);
}

