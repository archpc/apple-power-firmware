
void FUN_00001f88(undefined4 param_1,int param_2,int param_3,undefined1 param_4)

{
  *(undefined1 *)(param_2 + param_3) = param_4;
  *(undefined1 *)(param_2 + 0x33) = 0;
  *(undefined1 *)(param_2 + 0x10) = 2;
  FUN_00007b28();
  return;
}

