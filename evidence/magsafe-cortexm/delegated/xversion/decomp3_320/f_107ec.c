
/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_000107ec(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  ushort *in_r3;
  int unaff_r4;
  ushort unaff_r7;
  undefined8 uVar10;
  int in_stack_00000010;
  undefined4 uStack00000014;
  undefined1 *puStack00000018;
  int in_stack_00000024;
  uint uStack00000028;
  int in_stack_00000034;
  undefined1 in_stack_0000003c;
  ushort *puStack00000040;
  undefined1 in_stack_0000004c;
  int in_stack_00000050;
  uint in_stack_00000054;
  undefined4 *puStack00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  undefined4 *in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000074;
  undefined1 uStack00000078;
  undefined1 uStack00000079;
  undefined1 uStack0000007a;
  undefined1 uStack0000007b;
  undefined1 in_stack_0000007c;
  undefined1 in_stack_00000080;
  
  puVar7 = (ushort *)(in_stack_00000074 + 0x20);
  puStack00000018 = &stack0x00000079;
  uStack00000014 = 7;
  uStack00000028 = 0xe000;
  puStack00000058 = puRam00010b3c;
  iVar8 = 0;
  puStack00000040 = in_r3;
  do {
    uStack00000078 = in_stack_0000004c;
    if (iVar8 == 0x12) {
      iVar8 = FUN_00009fac((uint)*in_r3 + in_stack_00000050,&stack0x00000078,1);
      if (iVar8 != 0) {
        uVar6 = FUN_000107d6();
        return uVar6;
      }
      uVar6 = *in_stack_00000068;
      uVar2 = *puStack00000040;
      in_stack_00000080 = in_stack_0000003c;
      iVar8 = FUN_00009fac(in_stack_00000024,&stack0x00000080,1);
      if (iVar8 != 0) {
        uVar6 = FUN_000107d6();
        return uVar6;
      }
      FUN_000001a0(&stack0x00000078,0xff);
      in_stack_0000007c = (undefined1)((uint)uVar6 >> 0x18);
      uStack0000007b = (undefined1)((uint)uVar6 >> 0x10);
      uStack0000007a = (undefined1)((uint)uVar6 >> 8);
      uStack00000079 = (undefined1)uVar6;
      uStack00000078 = (undefined1)in_stack_00000060;
      iVar8 = FUN_00009fac(in_stack_00000024 + 1,&stack0x00000078,5);
      if (iVar8 != 0) {
        uVar6 = FUN_000107d6();
        return uVar6;
      }
      in_stack_00000080 = 0x3f;
      iVar8 = FUN_00009fac(in_stack_00000024,&stack0x00000080,1);
      if (iVar8 == 0) {
        uStack00000078 = (undefined1)uStack00000014;
        iVar8 = FUN_00009fac((uint)uVar2 + in_stack_00000050,&stack0x00000078,1);
        if (iVar8 != 0) {
          uVar6 = FUN_000107d6();
          return uVar6;
        }
        *puStack00000040 = unaff_r7;
        *(undefined1 *)(in_stack_0000006c + in_stack_00000060 + 0x10) = 0;
        if (in_stack_00000054 < 3) {
          uVar10 = FUN_0000a020(in_stack_00000010 + in_stack_00000050,in_stack_00000034);
          if ((int)uVar10 == 0) {
            FUN_0000ff42(0,(int)((ulonglong)uVar10 >> 0x20),in_stack_0000006c);
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          uVar6 = FUN_000107d6();
          return uVar6;
        }
        uVar6 = FUN_000107d6();
        return uVar6;
      }
      uVar6 = FUN_000107d6();
      return uVar6;
    }
    if ((in_stack_00000060 != iVar8) && (uVar3 = (uint)*puVar7, uVar3 != DAT_00010c08)) {
      uVar9 = (uint)*(byte *)(unaff_r4 + in_stack_0000005c) * in_stack_00000034;
      if ((uVar3 < (uVar9 & uStack00000028)) ||
         (in_r3 = puStack00000040, ((uint)(PTR_DAT_00010c10 + uVar9 + 0x1f) & 0xffff) < uVar3)) {
        uVar2 = *(ushort *)(unaff_r4 + 0x32);
        uVar9 = (uint)uVar2;
        if (((uint)(PTR_LAB_00005ffe_1_00010c0c +
                   in_stack_00000064 * (uint)*(byte *)(unaff_r4 + in_stack_0000005c)) & 0xffff) <
            uVar9) {
          return 0;
        }
        *(ushort *)(unaff_r4 + 0x32) = uVar2 + 0x20;
        iVar4 = FUN_00009fac(uVar3 + in_stack_00000050,&stack0x00000078,1);
        if (iVar4 != 0) {
          return 0;
        }
        if (uVar9 == DAT_00010c08) {
          return 0;
        }
        uVar6 = *puStack00000058;
        uVar1 = *puVar7;
        iVar4 = uVar9 + in_stack_00000050;
        in_stack_00000080 = in_stack_0000003c;
        iVar5 = FUN_00009fac(iVar4,&stack0x00000080,1);
        if (iVar5 != 0) {
          return 0;
        }
        FUN_000001a0(&stack0x00000078,0xff);
        puStack00000018[3] = (char)((uint)uVar6 >> 0x18);
        puStack00000018[2] = (char)((uint)uVar6 >> 0x10);
        puStack00000018[1] = (char)((uint)uVar6 >> 8);
        *puStack00000018 = (char)uVar6;
        uStack00000078 = (undefined1)iVar8;
        iVar5 = FUN_00009fac(iVar4 + 1,&stack0x00000078,5);
        if (iVar5 != 0) {
          uVar6 = FUN_000107d6();
          return uVar6;
        }
        in_stack_00000080 = 0x3f;
        iVar4 = FUN_00009fac(iVar4,&stack0x00000080,1);
        if (iVar4 != 0) {
          uVar6 = FUN_000107d6();
          return uVar6;
        }
        uStack00000078 = (undefined1)uStack00000014;
        iVar4 = FUN_00009fac((uint)uVar1 + in_stack_00000050,&stack0x00000078,1);
        if (iVar4 != 0) {
          uVar6 = FUN_000107d6();
          return uVar6;
        }
        *puVar7 = uVar2;
        *(undefined1 *)(in_stack_0000006c + iVar8 + 0x10) = 0;
        in_r3 = puStack00000040;
      }
    }
    puVar7 = puVar7 + 1;
    puStack00000058 = puStack00000058 + 1;
    iVar8 = iVar8 + 1;
  } while( true );
}

