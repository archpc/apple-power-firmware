
void FUN_000142ac(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int aiStack_17c [18];
  uint local_134 [72];
  
  for (iVar5 = 0; iVar5 != 0x40; iVar5 = iVar5 + 4) {
    uVar3 = *(uint *)(param_2 + iVar5);
    *(uint *)((int)local_134 + iVar5 + 0x20) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  }
  for (iVar5 = 0; iVar5 != 0xc0; iVar5 = iVar5 + 4) {
    uVar3 = *(uint *)((int)local_134 + iVar5 + 0x58);
    uVar4 = *(uint *)((int)local_134 + iVar5 + 0x24);
    *(uint *)((int)local_134 + iVar5 + 0x60) =
         *(int *)((int)local_134 + iVar5 + 0x20) + *(int *)((int)local_134 + iVar5 + 0x44) +
         ((uVar3 >> 0x11 | uVar3 << 0xf) ^ uVar3 >> 10 ^ (uVar3 >> 0x13 | uVar3 << 0xd)) +
         ((uVar4 >> 7 | uVar4 << 0x19) ^ uVar4 >> 3 ^ (uVar4 >> 0x12 | uVar4 << 0xe));
  }
  for (iVar5 = 0x48; iVar5 != 0x68; iVar5 = iVar5 + 4) {
    *(undefined4 *)((int)aiStack_17c + iVar5) = *(undefined4 *)(param_1 + iVar5);
  }
  for (iVar5 = 0; iVar5 != 0x40; iVar5 = iVar5 + 1) {
    iVar1 = *(int *)(DAT_000143e0 + iVar5 * 4) + local_134[7];
    uVar3 = local_134[iVar5 + 8];
    for (iVar2 = 0; iVar2 != -0x1c; iVar2 = iVar2 + -4) {
      *(undefined4 *)((int)local_134 + iVar2 + 0x1c) =
           *(undefined4 *)((int)local_134 + iVar2 + 0x18);
    }
    iVar1 = iVar1 + ((local_134[4] >> 0x19 | local_134[4] << 7) ^
                    (local_134[4] >> 6 | local_134[4] << 0x1a) ^
                    (local_134[4] >> 0xb | local_134[4] << 0x15)) +
            (local_134[6] & ~local_134[4] | local_134[5] & local_134[4]) + uVar3;
    local_134[4] = local_134[4] + iVar1;
    local_134[0] = ((local_134[0] >> 2 | local_134[0] << 0x1e) ^
                    (local_134[0] >> 0xd | local_134[0] << 0x13) ^
                   (local_134[0] << 10 | local_134[0] >> 0x16)) + iVar1 +
                   ((local_134[2] ^ local_134[1]) & local_134[0] ^ local_134[2] & local_134[1]);
  }
  for (iVar5 = 0x48; iVar5 != 0x68; iVar5 = iVar5 + 4) {
    *(int *)(param_1 + iVar5) = *(int *)((int)aiStack_17c + iVar5) + *(int *)(param_1 + iVar5);
  }
  return;
}

