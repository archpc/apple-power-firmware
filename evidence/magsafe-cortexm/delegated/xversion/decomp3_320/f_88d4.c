
undefined4 FUN_000088d4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_18;
  
  iVar4 = DAT_00008994 + param_1 * 0x1cc;
  local_18 = CONCAT22((short)((uint)param_4 >> 0x10),*(undefined2 *)(iVar4 + 0x3a));
  uVar3 = (uint)*(byte *)(iVar4 + 0x1a);
  if ((*(char *)(iVar4 + 0x1d) != '\0') &&
     ((*(uint *)(*(int *)(DAT_00008998 + param_1 * 4) + 0xa4) & 7) >> 1 != 0)) {
    return local_18;
  }
  if (*(char *)(iVar4 + 0x15) == '\x01') {
    uVar1 = FUN_0000899c(param_1,-uVar3 + 1 & 0xff,0);
    *(undefined1 *)((int)&local_18 + -uVar3 + 1) = uVar1;
    uVar1 = FUN_0000899c(param_1,uVar3,0);
    goto LAB_0000895c;
  }
  if (*(char *)(iVar4 + 0x1d) == '\0') {
    for (uVar3 = 0; uVar3 != 2; uVar3 = uVar3 + 1) {
      iVar4 = FUN_0000899c(param_1,uVar3 & 0xff,0);
      *(char *)((int)&local_18 + uVar3) = (char)iVar4;
      if (iVar4 != 0) {
        uVar1 = FUN_0000899c(param_1,uVar3 & 0xff,1);
        *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
      }
    }
    return local_18;
  }
  if (*(byte *)((int)&local_18 + uVar3) < 2) {
LAB_0000894a:
    uVar1 = FUN_0000899c(param_1,uVar3,0);
    *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
  }
  else {
    uVar2 = FUN_0000899c(param_1,uVar3,1);
    *(char *)((int)&local_18 + uVar3) = (char)uVar2;
    if (uVar2 < 2) goto LAB_0000894a;
  }
  uVar3 = (uint)*(byte *)(iVar4 + 0x1b);
  uVar1 = 0;
LAB_0000895c:
  *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
  return local_18;
}

