
void FUN_0000183c(int param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  bool bVar7;
  undefined1 auStack_114 [32];
  undefined1 auStack_f4 [32];
  undefined4 local_d4 [8];
  undefined1 auStack_b4 [32];
  undefined4 local_94 [10];
  undefined1 auStack_6c [24];
  undefined4 local_54 [12];
  undefined1 auStack_24 [16];
  
  FUN_000001a2(local_54,0,0x40);
  FUN_000017cc(local_54,param_2,0x10,param_3);
  FUN_00001970(local_94);
  for (iVar6 = 0; iVar6 != 0x30; iVar6 = iVar6 + 4) {
    *(undefined4 *)((int)local_94 + iVar6) = *(undefined4 *)((int)local_54 + iVar6);
  }
  FUN_000017cc(local_94,auStack_24,8,DAT_0000195c);
  FUN_00001970(local_d4);
  pcVar1 = DAT_00001964;
  for (iVar6 = 0; iVar6 != 0x28; iVar6 = iVar6 + 4) {
    *(undefined4 *)((int)local_d4 + iVar6) = *(undefined4 *)((int)local_94 + iVar6);
  }
  (*DAT_00001964)(local_d4,auStack_6c,6,DAT_00001960);
  pcVar2 = DAT_00001968;
  (*DAT_00001968)();
  (*pcVar2)(local_54);
  uVar3 = DAT_0000196c;
  (*pcVar1)(local_54,auStack_b4,6);
  FUN_00001776(auStack_114,local_d4,local_54,0xb);
  (*pcVar2)(local_54);
  (*pcVar1)(local_54,auStack_f4,3,uVar3);
  (*pcVar2)(local_94);
  FUN_00001776(local_94,auStack_114,local_54,10);
  bVar7 = false;
  while( true ) {
    puVar5 = local_54;
    if (!bVar7) {
      puVar5 = local_94;
    }
    iVar6 = FUN_0000173e(puVar5,DAT_0000196c,9);
    if (iVar6 < 1) break;
    puVar4 = local_94;
    if (!bVar7) {
      puVar4 = local_54;
    }
    FUN_00001776(puVar4,puVar5,DAT_0000196c,9);
    bVar7 = (bool)(bVar7 ^ 1);
  }
  puVar5 = local_54;
  if (!bVar7) {
    puVar5 = local_94;
  }
  for (iVar6 = 0; iVar6 != 0x20; iVar6 = iVar6 + 4) {
    *(undefined4 *)(param_1 + iVar6) = *(undefined4 *)((int)puVar5 + iVar6);
  }
  return;
}

