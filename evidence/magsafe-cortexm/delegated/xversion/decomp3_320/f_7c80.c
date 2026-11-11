
void FUN_00007c80(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  char local_18;
  
  iVar1 = *(int *)(DAT_00007d2c + param_1 * 4);
  *(undefined4 *)(iVar1 + 0x11c) = 0x80;
  *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) | 0x80;
  *(uint *)(iVar1 + 0x1a0) = *(uint *)(iVar1 + 0x1a0) | 1;
  *(uint *)(iVar1 + 0x18c) = *(uint *)(iVar1 + 0x18c) | 10;
  pcVar4 = (char *)(DAT_00007d30 + param_1 * 0x1cc);
  cVar3 = '\x01';
  pcVar4[0x19] = '\x01';
  if (pcVar4[1] == '\x01') {
    local_18 = '\x03';
  }
  else {
    local_18 = '\x04';
  }
  iVar1 = *(int *)(pcVar4 + 0x60);
  if (pcVar4[0x17] == '\0') {
    param_3 = 1;
    if ((pcVar4[0x11] == '\x01') && (*pcVar4 != '\x01')) {
      iVar2 = FUN_000079ac(param_1);
      param_2 = iVar1;
      if (iVar2 != 0) {
        cVar3 = (char)param_3;
        pcVar4[0x18] = cVar3;
        local_18 = '\x04';
        goto LAB_00007d0a;
      }
    }
    (**(code **)(iVar1 + 0x38))(param_1,0,*(code **)(iVar1 + 0x38),iVar1,param_2);
    cVar3 = (char)param_3;
  }
LAB_00007d0a:
  pcVar4[0x17] = cVar3;
  FUN_00003008(param_1);
  pcVar4[0x2d] = local_18;
  pcVar4[0x4c] = '\x02';
  pcVar4[0x4d] = '\0';
  pcVar4[0x4e] = '\0';
  pcVar4[0x4f] = '\0';
  (*(code *)**(undefined4 **)(pcVar4 + 0x60))
            (param_1,0x1b,0,(code *)**(undefined4 **)(pcVar4 + 0x60),param_2,param_3);
  return;
}

