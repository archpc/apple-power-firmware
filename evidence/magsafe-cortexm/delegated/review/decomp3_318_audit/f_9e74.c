
void FUN_00009e74(void)

{
  if (*(char *)(*(int *)(DAT_00009eac + 0x11c) + 0x21) != '\0') {
    FUN_00009e10(2);
    FUN_00000f28(DAT_00009eb0 + 0x58);
    return;
  }
  if (*(char *)(*(int *)(DAT_00009eac + 0x11c) + 0x2d) == '\b') {
    FUN_00009e34();
    return;
  }
  FUN_00009df8();
  return;
}

