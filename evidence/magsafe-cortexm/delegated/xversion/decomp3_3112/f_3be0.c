
void switchD_000036c0::caseD_8(int param_1,int param_2)

{
  uint uVar1;
  uint unaff_r4;
  int iVar2;
  uint *puVar3;
  
  param_2 = param_2 + param_1;
  if (*(char *)(param_2 + 0x1f) == '\x06') {
    (**(code **)(*(int *)(param_2 + 0x60) + 0x10))();
  }
  else {
    FUN_00002b28();
    if ((*(char *)(param_2 + 0x175) == '\0') &&
       (*(char *)(DAT_00003f2c + unaff_r4 * 0xf0 + 0xee) == '\0')) {
      FUN_00007160();
    }
    else {
      iVar2 = DAT_00003f2c + unaff_r4 * 0xf0;
      *(undefined1 *)(iVar2 + 0xee) = 0;
      if (*(char *)(param_2 + 0x176) == '\0') {
        puVar3 = (uint *)(param_2 + 0x180);
        for (uVar1 = 0; uVar1 != 6; uVar1 = uVar1 + 1) {
          puVar3[-0x32] = 0;
          if ((*(byte *)(param_2 + 0x17e) >> (uVar1 & 0xff) & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00003e26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)((uint)(byte)(&DAT_00003e28)[*puVar3 >> 0x1e] * 2 + 0x3e2a))();
            return;
          }
          puVar3 = puVar3 + 1;
        }
        *(undefined1 *)(param_2 + 0x177) = 0;
      }
      else if (unaff_r4 < 2) {
        *(undefined1 *)(param_2 + 0x176) = 0;
      }
      *(undefined1 *)(iVar2 + 0xe6) = 0x11;
      FUN_00007172();
    }
  }
  return;
}

