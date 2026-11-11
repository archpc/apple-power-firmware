
void FUN_0000807c(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  char *pcVar7;
  uint *puVar8;
  int iVar9;
  
  FUN_0000a908();
  iVar9 = *(int *)(DAT_000083c8 + param_1 * 4);
  puVar8 = (uint *)(iVar9 + 0x128);
  if (*(int *)(iVar9 + 0x130) != 0) {
    puVar5 = (undefined4 *)(DAT_000083cc + param_1 * 0x5c);
    if (*(int *)(iVar9 + 0x130) << 0x16 < 0) {
      *(undefined1 *)(puVar5 + 0x15) = 0;
      if ((*(uint *)(iVar9 + 0xa4) & 0xe00) == 0x400) {
        uVar3 = 0xc;
      }
      else {
        uVar3 = 8;
      }
      (*(code *)*puVar5)(param_1,uVar3);
      *(undefined4 *)(iVar9 + 0x118) = 0x220;
    }
    if (*(int *)(iVar9 + 0x130) << 0x18 < 0) {
      *(undefined4 *)(iVar9 + 0x118) = 0x80;
      *(undefined1 *)(puVar5 + 0x15) = 1;
    }
    if ((*(uint *)(iVar9 + 0x158) & 0x200) != 0) {
      if (*(int *)(iVar9 + 0x14c) << 0x15 < 0) {
        *(undefined1 *)((int)puVar5 + 0x55) = 0;
      }
      else {
        *(undefined1 *)((int)puVar5 + 0x55) = 1;
        *(char *)((int)puVar5 + 0x56) = (char)((*(uint *)(iVar9 + 0x5c) >> 0x10 & 0x1ff) + 3 >> 2);
        if (0x41 < *(byte *)((int)puVar5 + 0x56)) {
          *(undefined1 *)((int)puVar5 + 0x56) = 0x41;
        }
        *(undefined1 *)((int)puVar5 + 0x57) = 0;
        *(undefined1 *)(puVar5 + 0x16) = 0;
      }
      *(undefined4 *)(iVar9 + 0x14c) = 0x600;
    }
    if (*(int *)(iVar9 + 0x130) << 10 < 0) {
      FUN_000083d4(param_1);
      *(undefined4 *)(iVar9 + 0x118) = 0x200000;
    }
    if (*(int *)(iVar9 + 0x130) << 3 < 0) {
      uVar6 = *(uint *)(iVar9 + 0x118);
      if (((uVar6 & 0x38) == 0x18) && (*(char *)(puVar5 + 0x15) == '\x01')) {
        *(undefined1 *)(puVar5 + 0x15) = 0;
        *(uint *)(iVar9 + 0xd0) = *(uint *)(iVar9 + 0xd0) | 0x80000;
        *puVar8 = DAT_000083b0 & *puVar8;
        *(undefined4 *)(iVar9 + 0x118) = DAT_000083b4;
        (*(code *)*puVar5)(param_1,3);
      }
      if ((uVar6 & 0x21) == 1) {
        *(undefined1 *)(puVar5 + 0x15) = 0;
        *puVar8 = *puVar8 & 0xffffdfff;
        *(undefined4 *)(iVar9 + 0x118) = 0x2000;
        uVar4 = *(uint *)(iVar9 + 0xa4);
        uVar6 = *(uint *)(iVar9 + 0x5c);
        puVar5[2] = uVar6;
        *(char *)(puVar5 + 1) = (char)((uVar4 & 0x3f) >> 3) + -1;
        if (*(byte *)(DAT_000083d0 + param_1 * 0x1cc + 0x3e) < 2) {
          uVar6 = uVar6 & DAT_000083b8;
          puVar5[2] = uVar6;
        }
        *(char *)((int)puVar5 + 7) = (char)((uVar6 & 0x3f) >> 5);
        *(byte *)((int)puVar5 + 6) = (byte)uVar6 & 0x1f;
        *(char *)((int)puVar5 + 5) = (char)((uVar6 & 0x7fff) >> 0xc);
        if (*(char *)((int)puVar5 + 0x55) == '\0') {
          FUN_00008e94(puVar5 + 3,iVar9 + 0x60);
        }
        else {
          FUN_000083d4(param_1);
        }
        (*(code *)*puVar5)(param_1,6);
      }
      *(undefined4 *)(iVar9 + 0x118) = DAT_000083bc;
      *(undefined1 *)((int)puVar5 + 0x55) = 0;
      *(undefined4 *)(iVar9 + 0x14c) = 0xe00;
    }
    if (*(int *)(iVar9 + 0x130) << 0x14 < 0) {
      (*(code *)*puVar5)(param_1,7);
      *(undefined4 *)(iVar9 + 0x118) = 0x800;
    }
    if (*(int *)(iVar9 + 0x130) << 0xe < 0) {
      (*(code *)*puVar5)(param_1,7);
      *(undefined4 *)(iVar9 + 0x118) = 0x20000;
    }
    if ((*(uint *)(iVar9 + 0x130) & 0x2000) != 0) {
      *puVar8 = *puVar8 & 0xffffdfff;
      *(undefined4 *)(iVar9 + 0x118) = 0x2000;
      (*(code *)*puVar5)(param_1,1);
    }
    if (*(int *)(iVar9 + 0x130) << 0xb < 0) {
      iVar1 = FUN_0000843c(param_1,0);
      if (iVar1 == 0) {
        *puVar8 = *puVar8 & 0xffefffff;
      }
      *(undefined4 *)(iVar9 + 0x118) = 0x100000;
    }
    uVar6 = 0x400000;
    if (*(int *)(iVar9 + 0x130) << 0x11 < 0) {
      *(undefined1 *)(puVar5 + 0x15) = 0;
      if (*(char *)((int)puVar5 + 0x53) < '\0') {
        *puVar8 = DAT_000083b0 & *puVar8;
        (*(code *)*puVar5)(param_1,2);
      }
      else {
        pcVar7 = (char *)((int)puVar5 + 0x53);
        if (*pcVar7 != '\0') {
          *(undefined4 *)(iVar9 + 0x118) = 0x400000;
          FUN_00000b80(0xf0);
          puVar2 = puVar8;
          if (-1 < *(int *)(iVar9 + 0xf4) << 0xc) {
            puVar2 = (uint *)(iVar9 + 0xf4);
            uVar6 = 0x80000;
            FUN_00000b80(0xf0);
          }
          *puVar2 = *puVar2 | uVar6;
        }
        *pcVar7 = *pcVar7 + -1;
      }
      *(undefined4 *)(iVar9 + 0x118) = 0x4000;
    }
    if ((*(uint *)(iVar9 + 0x130) & 0x400000) != 0) {
      FUN_00000b80(0xf0);
      *(uint *)(iVar9 + 0xf4) = *(uint *)(iVar9 + 0xf4) | 0x80000;
      *puVar8 = *puVar8 & 0xffbfffff;
      *(undefined4 *)(iVar9 + 0x118) = 0x400000;
    }
    if ((*(uint *)(iVar9 + 0x130) & 0x1ffff) >> 0xf != 0) {
      (*(code *)*puVar5)(param_1,0);
      *(undefined4 *)(iVar9 + 0x118) = 0x1a000;
      *puVar8 = *puVar8 | 0x2000;
    }
    if ((*(uint *)(iVar9 + 0x130) & 0x100) != 0) {
      *(undefined1 *)(puVar5 + 0x15) = 0;
      (*(code *)*puVar5)(param_1,5);
      *puVar8 = DAT_000083c0 & *puVar8;
      *(undefined4 *)(iVar9 + 0x118) = DAT_000083c4;
    }
    if (*(int *)(iVar9 + 0x130) << 0xd < 0) {
      *(undefined1 *)(puVar5 + 0x15) = 0;
      *puVar8 = DAT_000083c0 & *puVar8;
      *(undefined4 *)(iVar9 + 0x118) = DAT_000083c4;
      (*(code *)*puVar5)(param_1,4);
    }
  }
  if (*(int *)(iVar9 + 0x158) != 0) {
    if (*(int *)(iVar9 + 0x158) << 0x18 < 0) {
      *(undefined4 *)(iVar9 + 0x14c) = 0x80;
    }
    if ((*(uint *)(iVar9 + 0x158) & 0x100) != 0) {
      *(undefined4 *)(iVar9 + 0x14c) = 0x100;
    }
  }
  return;
}

