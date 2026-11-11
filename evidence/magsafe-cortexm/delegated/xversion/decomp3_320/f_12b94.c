
void FUN_00012b94(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  puVar1 = DAT_00012bc8;
  *DAT_00012bc8 = *DAT_00012bc8 & 0xfffffffe;
  uVar2 = DAT_00012bd4;
  puVar4 = DAT_00012bcc;
  puVar5 = DAT_00012bd0;
  for (uVar3 = 0; uVar3 != 0x24; uVar3 = uVar3 + 1) {
    uVar6 = uVar2;
    if (uVar3 < 4) {
      uVar6 = *puVar4;
    }
    *puVar5 = uVar6;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
  }
  func_0x00000010();
  *puVar1 = *puVar1 | 1;
  return;
}

