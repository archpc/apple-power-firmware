
void FUN_00014550(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int aiStack_17c [18];
  uint local_134 [72];
  
  iVar1 = DAT_00014678;
  for (iVar2 = 0; iVar2 != 0x40; iVar2 = iVar2 + 4) {
    uVar6 = *(uint *)(DAT_00014678 + iVar2 + 4);
    *(uint *)((int)local_134 + iVar2 + 0x20) =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
  }
  for (iVar2 = 0; iVar2 != 0xc0; iVar2 = iVar2 + 4) {
    uVar7 = *(uint *)((int)local_134 + iVar2 + 0x24);
    uVar6 = *(uint *)((int)local_134 + iVar2 + 0x58);
    *(uint *)((int)local_134 + iVar2 + 0x60) =
         ((uVar6 >> 0x11 | uVar6 << 0xf) ^ (uVar6 >> 0x13 | uVar6 << 0xd) ^ uVar6 >> 10) +
         *(int *)((int)local_134 + iVar2 + 0x44) + *(int *)((int)local_134 + iVar2 + 0x20) +
         ((uVar7 >> 7 | uVar7 << 0x19) ^ (uVar7 >> 0x12 | uVar7 << 0xe) ^ uVar7 >> 3);
  }
  for (iVar2 = 0x48; iVar2 != 0x68; iVar2 = iVar2 + 4) {
    *(undefined4 *)((int)aiStack_17c + iVar2) = *(undefined4 *)(DAT_00014678 + iVar2);
  }
  for (iVar2 = 0; iVar2 != 0x40; iVar2 = iVar2 + 1) {
    iVar3 = (local_134[5] & local_134[4]) + local_134[7];
    uVar6 = local_134[iVar2 + 8];
    iVar4 = *(int *)(DAT_0001467c + iVar2 * 4);
    for (iVar5 = 0; iVar5 != -0x1c; iVar5 = iVar5 + -4) {
      *(undefined4 *)((int)local_134 + iVar5 + 0x1c) =
           *(undefined4 *)((int)local_134 + iVar5 + 0x18);
    }
    iVar3 = iVar3 + ((local_134[4] >> 0x19 | local_134[4] << 7) ^
                    (local_134[4] >> 6 | local_134[4] << 0x1a) ^
                    (local_134[4] >> 0xb | local_134[4] << 0x15)) + (local_134[6] & ~local_134[4]) +
            iVar4 + uVar6;
    local_134[4] = local_134[4] + iVar3;
    local_134[0] = ((local_134[0] >> 2 | local_134[0] << 0x1e) ^
                    (local_134[0] >> 0xd | local_134[0] << 0x13) ^
                   (local_134[0] >> 0x16 | local_134[0] << 10)) + iVar3 +
                   ((local_134[2] ^ local_134[1]) & local_134[0] ^ local_134[2] & local_134[1]);
  }
  for (iVar2 = 0x48; iVar2 != 0x68; iVar2 = iVar2 + 4) {
    *(int *)(iVar1 + iVar2) = *(int *)((int)aiStack_17c + iVar2) + *(int *)(iVar1 + iVar2);
  }
  return;
}

