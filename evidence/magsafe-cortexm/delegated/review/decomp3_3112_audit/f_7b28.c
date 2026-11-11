
void FUN_00007b28(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_18;
  
  iVar1 = *(int *)(DAT_00007bdc + param_1 * 4);
  *(undefined4 *)(iVar1 + 0x11c) = 0x80;
  *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) | 0x80;
  *(uint *)(iVar1 + 0x1a0) = *(uint *)(iVar1 + 0x1a0) | 1;
  *(uint *)(iVar1 + 0x18c) = *(uint *)(iVar1 + 0x18c) | 10;
  iVar1 = DAT_00007be0;
  iVar3 = DAT_00007be0 + param_1 * 0x1cc;
  *(undefined1 *)(iVar3 + 0x19) = 1;
  if (*(char *)(iVar3 + 1) == '\x01') {
    local_18 = 3;
  }
  else {
    local_18 = 4;
  }
  iVar2 = *(int *)(iVar3 + 0x60);
  if (*(char *)(iVar3 + 0x17) == '\0') {
    if (((*(char *)(iVar3 + 0x11) == '\x01') && (*(char *)(iVar1 + param_1 * 0x1cc) != '\x01')) &&
       (iVar1 = FUN_00007854(param_1), iVar1 != 0)) {
      *(undefined1 *)(iVar3 + 0x18) = 1;
      local_18 = 4;
    }
    else {
      (**(code **)(iVar2 + 0x38))(param_1,0);
    }
  }
  *(undefined1 *)(iVar3 + 0x17) = 1;
  FUN_00002f50(param_1);
  *(undefined1 *)(iVar3 + 0x2d) = local_18;
  *(undefined4 *)(iVar3 + 0x4c) = 2;
  (*(code *)**(undefined4 **)(iVar3 + 0x60))(param_1,0x1b,0);
  return;
}

