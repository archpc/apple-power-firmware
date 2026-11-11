
void FUN_000013dc(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0xc);
  puVar1[8] = 0xff;
  *puVar1 = 1;
  FUN_00000f54(*(undefined4 *)(puVar1 + 4));
  return;
}

