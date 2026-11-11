
void FUN_00005c84(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int unaff_r4;
  int unaff_r5;
  char *pcVar4;
  uint unaff_r7;
  int in_stack_00000008;
  
  pcVar4 = (char *)(DAT_00005ec4 + unaff_r4 * param_1 * 4);
  if (unaff_r7 == 0x12) {
    if (pcVar4[0x15] == '\0') {
      uVar2 = *(uint *)(in_stack_00000008 + 4);
      if ((((int)uVar2 < 0) && (DAT_00005eb4 <= (DAT_00005eb0 & uVar2))) &&
         ((uVar2 & 0x4000000) != 0)) {
        FUN_00007172();
        return;
      }
    }
    else if (((pcVar4[0x15] == '\x01') && (uVar2 = *(uint *)(in_stack_00000008 + 4), (int)uVar2 < 0)
             ) && (uVar3 = (uVar2 & 0x1ffffff) >> 0x10, 0x1a < uVar3)) {
      if ((uVar2 & 0x7fffffff) >> 0x1b != 0) {
        FUN_00000170(in_stack_00000008 + 0x22,in_stack_00000008 + 8,uVar3 - 0x1a);
LAB_00005e9c:
        FUN_00000170(in_stack_00000008 + 8,DAT_00005ecc,0x1a);
LAB_00005ea8:
        FUN_000031a0();
        return;
      }
      FUN_00000170(DAT_00005ecc,in_stack_00000008 + 8,0x1a);
    }
  }
  else {
    if (unaff_r7 == 0x10) {
      *(undefined1 *)(unaff_r5 + 0xa9) = 1;
      if ((DAT_00005eb0 & *(uint *)(in_stack_00000008 + 4)) != 0x20000) {
        return;
      }
      switch(*(undefined2 *)(in_stack_00000008 + 8)) {
      case 1:
        if (((*pcVar4 == '\0') || (-1 < (int)((uint)(byte)pcVar4[0x9e] << 0x18))) ||
           (-1 < (int)((uint)(byte)pcVar4[0x106] << 0x19))) break;
        *(undefined1 *)(unaff_r5 + 0xee) = 1;
        goto LAB_00005ea8;
      case 2:
        if (*pcVar4 != '\x01') goto LAB_00005ea8;
        break;
      case 3:
        if (pcVar4[0x15] == '\x01') {
          if (pcVar4[0x175] == '\0') {
            return;
          }
          FUN_00006388();
          return;
        }
        break;
      case 4:
        if (pcVar4[0x15] == '\0') {
          return;
        }
      }
      FUN_000062f4();
      return;
    }
    if (unaff_r7 != 0x11) {
      if (unaff_r7 == 6) {
        (*(code *)**(undefined4 **)(pcVar4 + 0x60))();
        pcVar4[0x43] = '\x02';
        FUN_00003038();
        return;
      }
      bVar1 = unaff_r7 - 3 < 2;
      if (bVar1) {
        (*(code *)**(undefined4 **)(pcVar4 + 0x60))();
      }
      if ((unaff_r7 < 0x10) && ((1 << (unaff_r7 & 0xff) & DAT_00005ebc) != 0)) {
        return;
      }
      pcVar4[0x43] = '\x02';
      FUN_00003038();
      if (bVar1) {
        return;
      }
      goto LAB_00005e0c;
    }
    if (pcVar4[0x15] == '\0') {
      uVar2 = *(uint *)(in_stack_00000008 + 4);
      if ((int)uVar2 < 0) {
        uVar3 = (uVar2 & 0x1ffffff) >> 0x10;
        if (uVar3 < 0x1b) goto LAB_00005ea8;
        uVar2 = (uVar2 & 0x7fffffff) >> 0x1b;
        if (uVar2 == 1) {
          FUN_000007f0(in_stack_00000008 + 0x22,in_stack_00000008 + 8,uVar3 - 0x1a);
          goto LAB_00005e9c;
        }
        if (uVar2 == 0) {
          FUN_00000170(DAT_00005ecc,in_stack_00000008 + 8,0x1a);
          FUN_00007172();
        }
      }
    }
    else {
      FUN_000062f4();
    }
  }
  pcVar4[0x43] = '\x02';
  FUN_00003038();
LAB_00005e0c:
  (*(code *)**(undefined4 **)(pcVar4 + 0x60))();
  return;
}

