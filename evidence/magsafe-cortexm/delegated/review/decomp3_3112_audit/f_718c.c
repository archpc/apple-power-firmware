
void FUN_0000718c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0000727c + param_1 * 0x1cc;
  if (param_2 - 4U < 2) {
    FUN_00007a6c(param_1,0,DAT_0000727c,param_4,param_4);
    iVar3 = DAT_00007280 + param_1 * 0xb;
    if (*(char *)(iVar3 + 4) == '\x01') {
      *(undefined1 *)(iVar3 + 4) = 0;
      if (*(char *)(iVar4 + 0x44) == '\0') {
        iVar3 = *(int *)(DAT_00007288 + param_1 * 4);
        *(undefined4 *)(iVar3 + 0x11c) = 0x80;
        *(uint *)(iVar3 + 300) = *(uint *)(iVar3 + 300) & 0xffffff7f;
      }
      FUN_00007af8(param_1,1);
      (*(code *)**(undefined4 **)(iVar4 + 0x60))(param_1,0x1a,0);
      *(undefined1 *)(iVar4 + 0x31) = 0;
      return;
    }
    *(undefined1 *)(iVar4 + 0x2d) = 1;
    uVar1 = 0xf;
    uVar2 = 0x32;
LAB_0000726e:
    FUN_00007800(param_1,uVar1,uVar2);
    return;
  }
  if (param_2 == 6) {
    FUN_00007af8(param_1,1);
    FUN_00007b28(param_1);
  }
  else if (param_2 == 1) {
    iVar3 = *(int *)(iVar4 + 0x60);
    FUN_0000c88c(param_1,0xf);
    if (*(char *)(DAT_00007280 + param_1 * 0xb + 4) == '\0') {
      *(undefined1 *)(iVar4 + 0x1d) = 0;
      (*(code *)**(undefined4 **)(iVar4 + 0x60))(param_1,1);
    }
    *(undefined1 *)(iVar4 + 0x19) = 1;
    if (*(char *)(iVar4 + 0x15) == '\0') {
      FUN_00007a6c(param_1,0);
      *(undefined1 *)(iVar4 + 0x2d) = 1;
    }
    else {
      FUN_00007a6c(param_1,1);
    }
    (**(code **)(iVar3 + 0x10))(param_1,DAT_00007284);
    uVar1 = 0x10;
    uVar2 = DAT_00007278;
    goto LAB_0000726e;
  }
  return;
}

