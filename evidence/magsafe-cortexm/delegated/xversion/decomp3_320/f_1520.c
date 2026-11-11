
void FUN_00001520(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int aiStack_17c [18];
  uint local_134 [72];
  
  for (iVar1 = 0; iVar1 != 0x40; iVar1 = iVar1 + 4) {
    uVar5 = *(uint *)(param_2 + iVar1);
    *(uint *)((int)local_134 + iVar1 + 0x20) =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
  }
  for (iVar1 = 0; iVar1 != 0xc0; iVar1 = iVar1 + 4) {
    uVar6 = *(uint *)((int)local_134 + iVar1 + 0x24);
    uVar5 = *(uint *)((int)local_134 + iVar1 + 0x58);
    *(uint *)((int)local_134 + iVar1 + 0x60) =
         ((uVar5 >> 0x11 | uVar5 << 0xf) ^ (uVar5 >> 0x13 | uVar5 << 0xd) ^ uVar5 >> 10) +
         *(int *)((int)local_134 + iVar1 + 0x44) + *(int *)((int)local_134 + iVar1 + 0x20) +
         ((uVar6 >> 7 | uVar6 << 0x19) ^ (uVar6 >> 0x12 | uVar6 << 0xe) ^ uVar6 >> 3);
  }
  for (iVar1 = 0x48; iVar1 != 0x68; iVar1 = iVar1 + 4) {
    *(undefined4 *)((int)aiStack_17c + iVar1) = *(undefined4 *)(param_1 + iVar1);
  }
  for (iVar1 = 0; iVar1 != 0x40; iVar1 = iVar1 + 1) {
    iVar2 = (local_134[5] & local_134[4]) + local_134[7];
    uVar5 = local_134[iVar1 + 8];
    iVar3 = *(int *)(DAT_00001644 + iVar1 * 4);
    for (iVar4 = 0; iVar4 != -0x1c; iVar4 = iVar4 + -4) {
      *(undefined4 *)((int)local_134 + iVar4 + 0x1c) =
           *(undefined4 *)((int)local_134 + iVar4 + 0x18);
    }
    iVar2 = iVar2 + ((local_134[4] >> 0x19 | local_134[4] << 7) ^
                    (local_134[4] >> 6 | local_134[4] << 0x1a) ^
                    (local_134[4] >> 0xb | local_134[4] << 0x15)) + (local_134[6] & ~local_134[4]) +
            iVar3 + uVar5;
    local_134[4] = local_134[4] + iVar2;
    local_134[0] = ((local_134[0] >> 2 | local_134[0] << 0x1e) ^
                    (local_134[0] >> 0xd | local_134[0] << 0x13) ^
                   (local_134[0] >> 0x16 | local_134[0] << 10)) + iVar2 +
                   ((local_134[2] ^ local_134[1]) & local_134[0] ^ local_134[2] & local_134[1]);
  }
  for (iVar1 = 0x48; iVar1 != 0x68; iVar1 = iVar1 + 4) {
    *(int *)(param_1 + iVar1) = *(int *)((int)aiStack_17c + iVar1) + *(int *)(param_1 + iVar1);
  }
  return;
}

