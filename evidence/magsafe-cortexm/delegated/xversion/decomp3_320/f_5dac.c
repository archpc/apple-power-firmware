
void FUN_00005dac(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_r5;
  uint unaff_r6;
  char *unaff_r7;
  int in_stack_00000008;
  
  if (unaff_r6 == 6) {
    (*(code *)**(undefined4 **)(unaff_r7 + 0x60))();
    unaff_r7[0x43] = '\x02';
    FUN_000030f0();
    return;
  }
  if (unaff_r6 == 0x12) {
    if (unaff_r7[0x15] == '\0') {
      uVar1 = *(uint *)(in_stack_00000008 + 4);
      if ((((int)uVar1 < 0) && (DAT_00005fc8 <= (DAT_00005fc4 & uVar1))) && ((int)(uVar1 << 5) < 0))
      {
        FUN_00007272();
        return;
      }
    }
    else if (((unaff_r7[0x15] == '\x01') &&
             (uVar1 = *(uint *)(in_stack_00000008 + 4), (int)uVar1 < 0)) &&
            (uVar2 = (uVar1 & 0x1ffffff) >> 0x10, 0x1a < uVar2)) {
      if ((uVar1 & 0x7fffffff) >> 0x1b != 0) {
        FUN_00000170(in_stack_00000008 + 0x22,in_stack_00000008 + 8,uVar2 - 0x1a);
LAB_00005fb0:
        FUN_00000170(in_stack_00000008 + 8,DAT_00005fe0,0x1a);
LAB_00005fbc:
        FUN_00003258();
        return;
      }
      FUN_00000170(DAT_00005fe0,in_stack_00000008 + 8,0x1a);
    }
  }
  else {
    if (unaff_r6 != 0x11) {
      if (unaff_r6 == 0x10) {
        *(undefined1 *)(unaff_r5 + 0xa9) = 1;
        if ((DAT_00005fc4 & *(uint *)(in_stack_00000008 + 4)) != 0x20000) {
          return;
        }
        switch(*(undefined2 *)(in_stack_00000008 + 8)) {
        case 1:
          if (((*unaff_r7 == '\0') || (-1 < (int)((uint)(byte)unaff_r7[0x9e] << 0x18))) ||
             (-1 < (int)((uint)(byte)unaff_r7[0x106] << 0x19))) break;
          *(undefined1 *)(unaff_r5 + 0xee) = 1;
          goto LAB_00005fbc;
        case 2:
          if (*unaff_r7 != '\x01') goto LAB_00005fbc;
          break;
        case 3:
          if (unaff_r7[0x15] == '\x01') {
            if (unaff_r7[0x175] == '\0') {
              return;
            }
            FUN_00006408();
            return;
          }
          break;
        case 4:
          if (unaff_r7[0x15] == '\0') {
            return;
          }
        }
        FUN_00006374();
        return;
      }
      if (unaff_r6 - 3 < 2) {
        (*(code *)**(undefined4 **)(unaff_r7 + 0x60))();
      }
      if ((unaff_r6 < 0x10) && ((1 << (unaff_r6 & 0xff) & DAT_00005fd0) != 0)) {
        return;
      }
      unaff_r7[0x43] = '\x02';
      FUN_000030f0();
      if (unaff_r6 - 3 < 2) {
        return;
      }
      goto LAB_00005f92;
    }
    if (unaff_r7[0x15] == '\0') {
      uVar1 = *(uint *)(in_stack_00000008 + 4);
      if ((int)uVar1 < 0) {
        uVar2 = (uVar1 & 0x1ffffff) >> 0x10;
        if (uVar2 < 0x1b) goto LAB_00005fbc;
        uVar1 = (uVar1 & 0x7fffffff) >> 0x1b;
        if (uVar1 == 1) {
          FUN_0000080c(in_stack_00000008 + 0x22,in_stack_00000008 + 8,uVar2 - 0x1a);
          goto LAB_00005fb0;
        }
        if (uVar1 == 0) {
          FUN_00000170(DAT_00005fe0,in_stack_00000008 + 8,0x1a);
          FUN_00007272();
        }
      }
    }
    else {
      FUN_00006374();
    }
  }
  unaff_r7[0x43] = '\x02';
  FUN_000030f0();
LAB_00005f92:
  (*(code *)**(undefined4 **)(unaff_r7 + 0x60))();
  return;
}

