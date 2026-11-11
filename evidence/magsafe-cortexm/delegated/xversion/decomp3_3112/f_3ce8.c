
void switchD_000036c0::caseD_4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int in_stack_0000001c;
  
  if ((param_1 == 0x11) && (uVar1 = *(uint *)(unaff_r5 + 4), (int)uVar1 < 0)) {
    if ((((int)(uVar1 << 5) < 0) && ((uVar1 & 0x7fffffff) >> 0x1b == 1)) &&
       (0x1a < ((uint)*(byte *)(in_stack_0000001c + unaff_r6 + 0x78) * 4 + 0x1c & 0x1fc))) {
      *(undefined1 *)(param_4 + 0xe6) = 0x11;
      FUN_00007172();
      return;
    }
LAB_00003eee:
    FUN_00005acc();
    FUN_00005a38();
  }
  else {
    iVar2 = FUN_00002fd4();
    if (iVar2 == 0) {
      iVar2 = FUN_00002fd4();
      if (iVar2 == 0) goto LAB_00003eee;
      if (*(char *)(in_stack_0000001c + unaff_r7) == '\0') goto LAB_00003dc4;
    }
    else if (*(char *)(in_stack_0000001c + unaff_r7) != '\0') {
LAB_00003dc4:
      FUN_000031a0();
      return;
    }
    FUN_00003088();
  }
  return;
}

