
void FUN_00001150(int param_1,undefined1 *param_2)

{
  byte bVar1;
  
  if (*(char *)(param_1 + 1) != '\0') {
    *param_2 = **(undefined1 **)(param_1 + 4);
    bVar1 = *(char *)(param_1 + 1) - 1;
    *(byte *)(param_1 + 1) = bVar1;
    if (bVar1 != 0) {
      **(undefined1 **)(param_1 + 4) = (*(undefined1 **)(param_1 + 4))[bVar1];
      FUN_000010a4(param_1,0);
    }
  }
  return;
}

