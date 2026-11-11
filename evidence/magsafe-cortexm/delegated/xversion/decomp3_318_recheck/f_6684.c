
void switchD_000060ea::caseD_13(void)

{
  int unaff_r6;
  int iVar1;
  
  (*(code *)**(undefined4 **)(unaff_r6 + 0x60))();
  if (*(char *)(unaff_r6 + 0x15) == '\x01') {
    FUN_000031a0();
    FUN_00003038();
    return;
  }
  iVar1 = *(int *)(unaff_r6 + 0x60);
  (**(code **)(iVar1 + 0x2c))();
  (**(code **)(iVar1 + 0x30))();
  (**(code **)(iVar1 + 0x34))();
  FUN_000031a0();
  return;
}

