
void FUN_0000c620(int param_1,int param_2,code *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_34;
  undefined1 auStack_30 [24];
  char local_18;
  undefined1 local_17;
  
  if (param_4 == 0) {
    iVar2 = 4;
  }
  else {
    iVar2 = 8;
  }
  uVar7 = *(uint *)(param_2 + 8 + iVar2);
  uVar5 = *(uint *)(param_2 + 8 + param_4 * 4);
  FUN_000001a2(&local_34,0);
  uVar1 = uVar5 & 0x7ff;
  uVar6 = uVar1 >> 6;
  uVar4 = DAT_0000c6d0;
  if (param_4 == 0) {
    uVar4 = DAT_0000c6d0 + 0xf;
  }
  iVar2 = DAT_0000c6d4;
  if (((param_1 == 1) || (iVar2 = DAT_0000c6d8, param_1 == 0)) &&
     (uVar3 = uVar7 & 0xffff, (uVar6 < 0x15 && (uVar7 & 0x7000000) == 0) && uVar3 + uVar6 < 9)) {
    uVar4 = uVar4 + uVar6 * 0x40;
    FUN_00000170(auStack_30,iVar2 + uVar3,uVar6);
  }
  else {
    uVar4 = uVar4 & DAT_0000c6d0 + 1 | 0x20;
  }
  local_17 = 0;
  local_18 = (char)(uVar1 >> 8);
  if ((uVar5 & 0xff) >> 6 != 0) {
    local_18 = local_18 + '\x01';
  }
  local_18 = local_18 + '\x01';
  local_34 = uVar4;
  (*param_3)(param_1);
  return;
}

