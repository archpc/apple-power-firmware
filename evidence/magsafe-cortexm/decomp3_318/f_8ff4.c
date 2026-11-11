
void FUN_00008ff4(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_14;
  
  iVar2 = DAT_00009050;
  iVar1 = DAT_00009048;
  uVar3 = (uint)*(byte *)(DAT_00009050 + 6);
  if ((uVar3 != 0) && (*(char *)(DAT_00009050 + 5) == '\0')) {
    if (*(int *)(DAT_00009050 + 0x58) + uVar3 >> 0x10 == 0) {
      local_14 = param_4;
      FUN_00009fa4(*(int *)(DAT_00009050 + 0x58) + 0x30000,DAT_00009054 + 0x28,uVar3,param_4,param_3
                  );
      *(uint *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + (uint)*(byte *)(iVar2 + 6);
    }
    else {
      *(undefined1 *)(DAT_00009050 + 5) = 1;
      *(int *)(iVar2 + 0x58) = iVar1 + 1;
      local_14 = param_4 & 0xffffff00;
      FUN_00009fa4(DAT_0000904c,&local_14,1,param_4,param_3);
      FUN_00009604(1);
    }
    *(undefined1 *)(iVar2 + 6) = 0;
  }
  return;
}

