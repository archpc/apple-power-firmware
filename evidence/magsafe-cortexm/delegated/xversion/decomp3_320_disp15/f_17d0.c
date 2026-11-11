
void FUN_000017d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined1 auStack_114 [32];
  undefined1 auStack_f4 [32];
  undefined4 local_d4 [8];
  undefined1 auStack_b4 [32];
  undefined4 local_94 [10];
  undefined1 auStack_6c [24];
  undefined4 local_54 [12];
  undefined1 auStack_24 [16];
  
  FUN_000001a0(local_54,0,0x40);
  FUN_0000175a(local_54,param_2,0x10,param_3);
  FUN_000018f8(local_94);
  for (iVar5 = 0; iVar5 != 0x30; iVar5 = iVar5 + 4) {
    *(undefined4 *)((int)local_94 + iVar5) = *(undefined4 *)((int)local_54 + iVar5);
  }
  FUN_0000175a(local_94,auStack_24,8,DAT_000018e4);
  FUN_000018f8(local_d4);
  pcVar1 = DAT_000018ec;
  for (iVar5 = 0; iVar5 != 0x28; iVar5 = iVar5 + 4) {
    *(undefined4 *)((int)local_d4 + iVar5) = *(undefined4 *)((int)local_94 + iVar5);
  }
  (*DAT_000018ec)(local_d4,auStack_6c,6,DAT_000018e8);
  pcVar2 = DAT_000018f0;
  (*DAT_000018f0)();
  (*pcVar2)(local_54);
  uVar3 = DAT_000018f4;
  (*pcVar1)(local_54,auStack_b4,6);
  FUN_00001706(auStack_114,local_d4,local_54,0xb);
  (*pcVar2)(local_54);
  (*pcVar1)(local_54,auStack_f4,3,uVar3);
  (*pcVar2)(local_94);
  FUN_00001706(local_94,auStack_114,local_54,10);
  bVar7 = false;
  while( true ) {
    puVar6 = local_54;
    if (!bVar7) {
      puVar6 = local_94;
    }
    iVar5 = FUN_000016d0(puVar6,DAT_000018f4,9);
    if (iVar5 < 1) break;
    puVar4 = local_94;
    if (!bVar7) {
      puVar4 = local_54;
    }
    FUN_00001706(puVar4,puVar6,DAT_000018f4,9);
    bVar7 = (bool)(bVar7 ^ 1);
  }
  for (iVar5 = 0; iVar5 != 0x20; iVar5 = iVar5 + 4) {
    *(undefined4 *)(param_1 + iVar5) = *(undefined4 *)((int)puVar6 + iVar5);
  }
  return;
}

