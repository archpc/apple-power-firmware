
void FUN_00007f2c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  char *pcVar7;
  uint *puVar8;
  int iVar9;
  
  FUN_0000a7d0();
  iVar9 = *(int *)(DAT_00008278 + param_1 * 4);
  puVar8 = (uint *)(iVar9 + 0x128);
  if (*(int *)(iVar9 + 0x130) != 0) {
    puVar5 = (undefined4 *)(DAT_0000827c + param_1 * 0x5c);
    if (*(int *)(iVar9 + 0x130) << 0x16 < 0) {
      *(undefined1 *)(puVar5 + 0x15) = 0;
      if ((*(uint *)(iVar9 + 0xa4) & 0xe00) == 0x400) {
        uVar2 = 0xc;
      }
      else {
        uVar2 = 8;
      }
      (*(code *)*puVar5)(param_1,uVar2);
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
      FUN_00008284(param_1);
      *(undefined4 *)(iVar9 + 0x118) = 0x200000;
    }
    if (*(int *)(iVar9 + 0x130) << 3 < 0) {
      uVar6 = *(uint *)(iVar9 + 0x118);
      if (((uVar6 & 0x38) == 0x18) && (*(char *)(puVar5 + 0x15) == '\x01')) {
        *(undefined1 *)(puVar5 + 0x15) = 0;
        *(uint *)(iVar9 + 0xd0) = *(uint *)(iVar9 + 0xd0) | 0x80000;
        *puVar8 = DAT_00008260 & *puVar8;
        *(undefined4 *)(iVar9 + 0x118) = DAT_00008264;
        (*(code *)*puVar5)(param_1,3);
      }
      if ((uVar6 & 0x21) == 1) {
        *(undefined1 *)(puVar5 + 0x15) = 0;
        *puVar8 = *puVar8 & 0xffffdfff;
        *(undefined4 *)(iVar9 + 0x118) = 0x2000;
        uVar3 = *(uint *)(iVar9 + 0xa4);
        uVar6 = *(uint *)(iVar9 + 0x5c);
        puVar5[2] = uVar6;
        *(char *)(puVar5 + 1) = (char)((uVar3 & 0x3f) >> 3) + -1;
        if (*(byte *)(DAT_00008280 + param_1 * 0x1cc + 0x3e) < 2) {
          uVar6 = uVar6 & DAT_00008268;
          puVar5[2] = uVar6;
        }
        *(char *)((int)puVar5 + 7) = (char)((uVar6 & 0x3f) >> 5);
        *(byte *)((int)puVar5 + 6) = (byte)uVar6 & 0x1f;
        *(char *)((int)puVar5 + 5) = (char)((uVar6 & 0x7fff) >> 0xc);
        if (*(char *)((int)puVar5 + 0x55) == '\0') {
          FUN_00008d54(puVar5 + 3,iVar9 + 0x60);
        }
        else {
          FUN_00008284(param_1);
        }
        (*(code *)*puVar5)(param_1,6);
      }
      *(undefined4 *)(iVar9 + 0x118) = DAT_0000826c;
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
      iVar1 = FUN_000082ec(param_1,0);
      if (iVar1 == 0) {
        *puVar8 = *puVar8 & 0xffefffff;
      }
      *(undefined4 *)(iVar9 + 0x118) = 0x100000;
    }
    uVar6 = 0x400000;
    if (*(int *)(iVar9 + 0x130) << 0x11 < 0) {
      *(undefined1 *)(puVar5 + 0x15) = 0;
      if (*(char *)((int)puVar5 + 0x53) < '\0') {
        *puVar8 = DAT_00008260 & *puVar8;
        (*(code *)*puVar5)(param_1,2);
      }
      else {
        pcVar7 = (char *)((int)puVar5 + 0x53);
        if (*pcVar7 != '\0') {
          *(undefined4 *)(iVar9 + 0x118) = 0x400000;
          FUN_00000b60(0xf0);
          puVar4 = puVar8;
          if (-1 < *(int *)(iVar9 + 0xf4) << 0xc) {
            uVar6 = 0x80000;
            FUN_00000b60(0xf0);
            puVar4 = (uint *)(iVar9 + 0xf4);
          }
          *puVar4 = *puVar4 | uVar6;
        }
        *pcVar7 = *pcVar7 + -1;
      }
      *(undefined4 *)(iVar9 + 0x118) = 0x4000;
    }
    if ((*(uint *)(iVar9 + 0x130) & 0x400000) != 0) {
      FUN_00000b60(0xf0);
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
      *puVar8 = DAT_00008270 & *puVar8;
      *(undefined4 *)(iVar9 + 0x118) = DAT_00008274;
    }
    if (*(int *)(iVar9 + 0x130) << 0xd < 0) {
      *(undefined1 *)(puVar5 + 0x15) = 0;
      *puVar8 = DAT_00008270 & *puVar8;
      *(undefined4 *)(iVar9 + 0x118) = DAT_00008274;
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

