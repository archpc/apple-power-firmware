
void FUN_00009128(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_14;
  
  iVar2 = DAT_00009184;
  iVar1 = DAT_0000917c;
  uVar3 = (uint)*(byte *)(DAT_00009184 + 6);
  if ((uVar3 != 0) && (*(char *)(DAT_00009184 + 5) == '\0')) {
    if (*(int *)(DAT_00009184 + 100) + uVar3 >> 0x10 == 0) {
      local_14 = param_4;
      FUN_00009fac(*(int *)(DAT_00009184 + 100) + 0x30000,DAT_00009188 + 0x20,uVar3,param_4,param_3)
      ;
      *(uint *)(iVar2 + 100) = *(int *)(iVar2 + 100) + (uint)*(byte *)(iVar2 + 6);
    }
    else {
      *(undefined1 *)(DAT_00009184 + 5) = 1;
      *(int *)(iVar2 + 100) = iVar1 + 1;
      local_14 = param_4 & 0xffffff00;
      FUN_00009fac(DAT_00009180,&local_14,1,param_4,param_3);
      FUN_000096f8(1);
    }
    *(undefined1 *)(iVar2 + 6) = 0;
  }
  return;
}

