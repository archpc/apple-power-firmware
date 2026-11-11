
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000e940(int param_1)

{
  int in_stack_00000018;
  
  *(undefined4 *)(DAT_0000f114 + 0x4c) = 1;
  _MasterStackPointer = param_1 * 0x800 + in_stack_00000018 * 0x40 + 0x10;
  return 1;
}

