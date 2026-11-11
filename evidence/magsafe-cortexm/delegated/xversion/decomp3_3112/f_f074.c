
int FUN_0000f074(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 local_30;
  int local_2c;
  undefined *local_28;
  undefined2 local_18;
  undefined2 local_16;
  
  FUN_000001a2(&local_30,0,0x1c);
  pcVar1 = DAT_0000f17c;
  local_16 = (undefined2)param_1;
  local_18 = 0;
  local_28 = PTR_DAT_0000f174;
  local_30 = param_3;
  local_2c = param_2;
  iVar3 = (*DAT_0000f17c)(&local_30,PTR_DAT_0000f178);
  iVar4 = (*pcVar1)(&local_30,PTR_DAT_0000f180);
  iVar5 = (*pcVar1)(&local_30,PTR_DAT_0000f184,DAT_0000f170);
  iVar6 = (*pcVar1)(&local_30,DAT_0000f18c,*(undefined1 *)(DAT_0000f188 + 0x5d));
  puVar2 = DAT_0000f190;
  iVar7 = *DAT_0000f190 - DAT_0000f190[1];
  if (*DAT_0000f190 < DAT_0000f190[1]) {
    iVar7 = 0;
  }
  iVar7 = (*pcVar1)(&local_30,DAT_0000f194,iVar7);
  iVar8 = puVar2[2] - puVar2[3];
  if (puVar2[2] < puVar2[3]) {
    iVar8 = 0;
  }
  iVar8 = (*pcVar1)(&local_30,DAT_0000f198,iVar8);
  iVar9 = puVar2[4] - puVar2[5];
  if (puVar2[4] < puVar2[5]) {
    iVar9 = 0;
  }
  iVar9 = (*pcVar1)(&local_30,DAT_0000f19c,iVar9);
  iVar10 = puVar2[6] - puVar2[7];
  if (puVar2[6] < puVar2[7]) {
    iVar10 = 0;
  }
  iVar10 = (*pcVar1)(&local_30,DAT_0000f1a0,iVar10);
  iVar11 = puVar2[8] - puVar2[9];
  if (puVar2[8] < puVar2[9]) {
    iVar11 = 0;
  }
  iVar11 = (*pcVar1)(&local_30,DAT_0000f1a4,iVar11);
  iVar12 = puVar2[10] - puVar2[0xb];
  if (puVar2[10] < puVar2[0xb]) {
    iVar12 = 0;
  }
  iVar12 = (*pcVar1)(&local_30,DAT_0000f1a8,iVar12);
  iVar13 = puVar2[0xc] - puVar2[0xd];
  if (puVar2[0xc] < puVar2[0xd]) {
    iVar13 = 0;
  }
  iVar13 = (*pcVar1)(&local_30,DAT_0000f1ac,iVar13);
  iVar14 = puVar2[0xe] - puVar2[0xf];
  if (puVar2[0xe] < puVar2[0xf]) {
    iVar14 = 0;
  }
  iVar14 = (*pcVar1)(&local_30,DAT_0000f1b0,iVar14);
  iVar14 = (iVar3 - param_1) + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 +
           iVar12 + iVar13 + iVar14;
  if (iVar14 <= param_2) {
    param_2 = iVar14;
  }
  return param_2;
}

