
undefined8 FUN_00008778(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_18;
  
  iVar4 = DAT_0000883c + param_1 * 0x1cc;
  local_18 = CONCAT22((short)((uint)param_4 >> 0x10),*(undefined2 *)(iVar4 + 0x3a));
  uVar3 = (uint)*(byte *)(iVar4 + 0x1a);
  if ((*(char *)(iVar4 + 0x1d) != '\0') &&
     ((*(uint *)(*(int *)(DAT_00008840 + param_1 * 4) + 0xa4) & 7) >> 1 != 0)) goto LAB_00008808;
  if (*(char *)(iVar4 + 0x15) == '\x01') {
    uVar5 = 0;
    uVar1 = FUN_00008844(param_1,-uVar3 + 1 & 0xff);
    *(undefined1 *)((int)&local_18 + -uVar3 + 1) = uVar1;
    uVar1 = FUN_00008844(param_1,uVar3,uVar5);
    *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
    goto LAB_00008808;
  }
  if (*(char *)(iVar4 + 0x1d) == '\0') {
    for (uVar3 = 0; uVar3 != 2; uVar3 = uVar3 + 1) {
      iVar4 = FUN_00008844(param_1,uVar3 & 0xff,0);
      *(char *)((int)&local_18 + uVar3) = (char)iVar4;
      if (iVar4 != 0) {
        uVar1 = FUN_00008844(param_1,uVar3 & 0xff,1);
        *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
      }
    }
    goto LAB_00008808;
  }
  if (*(byte *)((int)&local_18 + uVar3) < 2) {
LAB_000087f2:
    uVar1 = FUN_00008844(param_1,uVar3,0);
    *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
  }
  else {
    uVar2 = FUN_00008844(param_1,uVar3,1,param_4,param_2,param_3);
    *(char *)((int)&local_18 + uVar3) = (char)uVar2;
    if (uVar2 < 2) goto LAB_000087f2;
  }
  *(undefined1 *)((int)&local_18 + (uint)*(byte *)(iVar4 + 0x1b)) = 0;
LAB_00008808:
  return CONCAT44(param_2,local_18);
}

