
void FUN_00005a80(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 auStack_32 [26];
  int local_18;
  
  pcVar2 = DAT_00005ac8;
  iVar1 = DAT_00005ac4;
  param_1 = param_1 * 0xf0;
  iVar3 = *(int *)(DAT_00005ac4 + param_1);
  local_18 = (uint)*(ushort *)(iVar3 + 8) * 0x10000 + (uint)*(ushort *)(iVar3 + 4);
  (*DAT_00005ac8)(iVar3 + 4,&local_18,4);
  iVar3 = *(int *)(iVar1 + param_1);
  uVar4 = *(undefined4 *)(iVar3 + 8);
  local_33 = (undefined1)((uint)uVar4 >> 0x18);
  local_34 = (undefined1)((uint)uVar4 >> 0x10);
  (*pcVar2)(auStack_32,iVar3 + 0xc,0x1a);
  (*pcVar2)(*(int *)(iVar1 + param_1) + 8,&local_34,0x1c);
  return;
}

