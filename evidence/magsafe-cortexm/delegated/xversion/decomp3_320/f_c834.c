
void FUN_0000c834(int param_1,int param_2,code *param_3,int param_4)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_34;
  undefined1 auStack_30 [24];
  char local_18;
  undefined1 local_17;
  
  if (param_4 == 0) {
    iVar3 = 4;
  }
  else {
    iVar3 = 8;
  }
  uVar4 = *(uint *)(param_2 + 8 + iVar3);
  uVar5 = *(uint *)(param_2 + 8 + param_4 * 4);
  bVar2 = false;
  FUN_000001a0(&local_34,0,0x20);
  if (param_4 == 0) {
    iVar3 = 0x11;
  }
  else {
    iVar3 = 2;
  }
  uVar1 = uVar5 & 0x7ff;
  uVar7 = uVar1 >> 6;
  if (uVar7 < 0x15) {
    if ((uVar4 & 0x7ffffff) >> 0x18 != 0) {
      bVar2 = true;
    }
  }
  else {
    bVar2 = true;
  }
  uVar6 = uVar7 * 0x40 + iVar3 + DAT_0000c8fc;
  iVar3 = DAT_0000c900;
  if (((param_1 != 1) && (iVar3 = DAT_0000c904, param_1 != 0)) ||
     (uVar4 = uVar4 & 0xffff, 8 < uVar4 + uVar7 || bVar2)) {
    uVar6 = uVar6 & DAT_0000c8fc + 3U | 0x20;
  }
  else {
    FUN_00000170(auStack_30,iVar3 + uVar4,uVar7);
  }
  local_17 = 0;
  local_18 = (char)(uVar1 >> 8);
  if ((uVar5 & 0xff) >> 6 != 0) {
    local_18 = local_18 + '\x01';
  }
  local_18 = local_18 + '\x01';
  local_34 = uVar6;
  (*param_3)(param_1);
  return;
}

