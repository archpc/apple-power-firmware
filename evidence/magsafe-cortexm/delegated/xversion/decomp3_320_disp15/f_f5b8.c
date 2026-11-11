
undefined4
FUN_0000f5b8(int param_1,uint param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
            int param_7)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined4 *unaff_r5;
  undefined4 uVar15;
  undefined4 *puVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint in_stack_0000001c;
  undefined1 in_stack_00000020;
  undefined1 in_stack_00000024;
  int in_stack_00000028;
  uint uStack0000002c;
  undefined1 *in_stack_00000034;
  undefined1 *in_stack_00000038;
  int in_stack_0000003c;
  undefined1 *in_stack_00000040;
  undefined1 *in_stack_00000044;
  undefined1 *in_stack_00000048;
  int in_stack_0000004c;
  undefined1 *in_stack_00000050;
  int in_stack_0000005c;
  uint in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  uint *in_stack_0000006c;
  uint in_stack_00000070;
  undefined4 *puStack00000074;
  int in_stack_00000078;
  undefined4 *in_stack_00000080;
  ushort *in_stack_00000084;
  int in_stack_00000088;
  int in_stack_0000008c;
  undefined1 uStack00000090;
  undefined1 in_stack_00000098;
  
code_r0x0000f5b8:
  param_5 = param_2 * param_3;
  puVar10 = (ushort *)(param_4 + 0x20);
  iVar19 = 0;
  while( true ) {
    if (iVar19 == 0x12) {
      return 0;
    }
    if ((param_5 + param_1 & 0xffffU) == (uint)*puVar10) break;
    puVar10 = puVar10 + 1;
    unaff_r5 = unaff_r5 + 1;
    iVar19 = iVar19 + 1;
  }
  puVar9 = (ushort *)(param_4 + 0x20);
  param_6 = 7;
  uStack0000002c = 0xe000;
  puStack00000074 = DAT_0000fbb4;
  for (iVar18 = 0; uStack00000090 = in_stack_00000024, iVar18 != 0x12; iVar18 = iVar18 + 1) {
    if ((iVar19 != iVar18) && (uVar13 = (uint)*puVar9, uVar13 != DAT_0000fbbc)) {
      uVar7 = (uint)*(byte *)(in_stack_00000078 + in_stack_0000005c) * in_stack_0000003c;
      if ((uVar13 < (uVar7 & uStack0000002c)) || ((DAT_0000fbc0 + uVar7 + 0x1f & 0xffff) < uVar13))
      {
        uVar1 = *(ushort *)(in_stack_00000078 + 0x32);
        uVar7 = (uint)uVar1;
        if ((in_stack_00000028 * (uint)*(byte *)(in_stack_00000078 + in_stack_0000005c) +
             DAT_0000fbb8 & 0xffff) < uVar7) {
          return 0;
        }
        *(ushort *)(in_stack_00000078 + 0x32) = uVar1 + 0x20;
        iVar3 = FUN_00009fac(uVar13 + in_stack_0000008c,&stack0x00000090,1);
        if (iVar3 != 0) {
          return 0;
        }
        if (uVar7 == DAT_0000fbbc) {
          return 0;
        }
        uVar15 = *puStack00000074;
        uVar2 = *puVar9;
        iVar3 = uVar7 + in_stack_0000008c;
        in_stack_00000098 = in_stack_00000020;
        iVar4 = FUN_00009fac(iVar3,&stack0x00000098,1);
        if (iVar4 != 0) {
          return 0;
        }
        FUN_000001a0(&stack0x00000090,0xff);
        in_stack_00000048[3] = (char)((uint)uVar15 >> 0x18);
        in_stack_00000048[2] = (char)((uint)uVar15 >> 0x10);
        in_stack_00000048[1] = (char)((uint)uVar15 >> 8);
        *in_stack_00000048 = (char)uVar15;
        uStack00000090 = (undefined1)iVar18;
        iVar4 = FUN_00009fac(iVar3 + 1,&stack0x00000090,5);
        if (iVar4 != 0) {
          return 0;
        }
        in_stack_00000098 = 0x3f;
        iVar3 = FUN_00009fac(iVar3,&stack0x00000098,1);
        if (iVar3 != 0) {
          return 0;
        }
        uStack00000090 = (undefined1)param_6;
        iVar3 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x00000090,1);
        if (iVar3 != 0) {
          return 0;
        }
        *puVar9 = uVar1;
        *(undefined1 *)(in_stack_00000064 + iVar18 + 0x10) = 0;
      }
    }
    puVar9 = puVar9 + 1;
    puStack00000074 = puStack00000074 + 1;
  }
  iVar18 = FUN_00009fac((uint)*puVar10 + in_stack_0000008c,&stack0x00000090,1);
  if (iVar18 == 0) {
    uVar15 = *unaff_r5;
    puStack00000074 = (undefined4 *)(uint)*puVar10;
    in_stack_00000098 = in_stack_00000020;
    iVar18 = FUN_00009fac(param_7,&stack0x00000098,1);
    if (iVar18 == 0) {
      FUN_000001a0(&stack0x00000090,0xff);
      in_stack_00000038[3] = (char)((uint)uVar15 >> 0x18);
      in_stack_00000038[2] = (char)((uint)uVar15 >> 0x10);
      in_stack_00000038[1] = (char)((uint)uVar15 >> 8);
      *in_stack_00000038 = (char)uVar15;
      uStack00000090 = (undefined1)iVar19;
      iVar18 = FUN_00009fac(param_7 + 1,&stack0x00000090,5);
      if (iVar18 == 0) {
        in_stack_00000098 = 0x3f;
        iVar18 = FUN_00009fac(param_7,&stack0x00000098,1);
        if (iVar18 == 0) {
          uStack00000090 = (undefined1)param_6;
          iVar18 = FUN_00009fac((int)puStack00000074 + in_stack_0000008c,&stack0x00000090,1);
          if (iVar18 == 0) {
            *puVar10 = (ushort)in_stack_00000060;
            *(undefined1 *)(in_stack_00000064 + iVar19 + 0x10) = 0;
            if (((in_stack_0000001c < 3) &&
                (iVar19 = FUN_0000a020(param_5 + in_stack_0000008c,in_stack_0000003c), iVar19 == 0))
               && (in_stack_00000060 = (uint)*(ushort *)(in_stack_00000078 + 0x32),
                  in_stack_00000060 <=
                  ((uint)*(byte *)(in_stack_00000078 + in_stack_0000005c) * in_stack_00000028 +
                   DAT_0000fbb8 & 0xffff))) {
              uVar13 = *in_stack_0000006c;
LAB_0000f5de:
              *in_stack_00000084 = (ushort)in_stack_00000060;
              *(ushort *)(in_stack_00000078 + 0x32) = (ushort)in_stack_00000060 + 0x20;
              if (in_stack_00000060 != DAT_0000f7a8) {
                in_stack_00000098 = 0x7f;
                iVar18 = in_stack_00000060 + in_stack_0000008c;
                iVar19 = FUN_00009fac(iVar18,&stack0x00000098,1);
                if (iVar19 == 0) {
                  FUN_000001a0(&stack0x00000090,0xff,5);
                  in_stack_00000050[3] = (char)(uVar13 >> 0x18);
                  in_stack_00000050[2] = (char)(uVar13 >> 0x10);
                  in_stack_00000050[1] = (char)(uVar13 >> 8);
                  *in_stack_00000050 = (char)uVar13;
                  uStack00000090 = (undefined1)in_stack_00000070;
                  iVar19 = FUN_00009fac(iVar18 + 1,&stack0x00000090,5);
                  if (iVar19 == 0) {
                    in_stack_00000098 = 0x3f;
                    iVar19 = FUN_00009fac(iVar18,&stack0x00000098,1);
LAB_0000f648:
                    if (iVar19 == 0) {
                      do {
                        while( true ) {
                          uVar7 = (uint)*(byte *)(in_stack_00000068 + 0x10);
                          uVar8 = uVar7 + (int)in_stack_00000080;
                          *(char *)(in_stack_00000068 + 0x10) = (char)uVar8;
                          *in_stack_0000006c = *in_stack_0000006c + (int)in_stack_00000080;
                          uVar13 = (uint)*in_stack_00000084;
                          if (uVar13 == DAT_0000f7a8) {
                            return 0;
                          }
                          uVar11 = uVar8 & 0xff;
                          if (7 < uVar11) {
                            uVar11 = 8;
                          }
                          iVar19 = uVar7 + 7;
                          uVar11 = (iVar19 + (int)in_stack_00000080) - uVar11;
                          uVar12 = 0xff;
                          for (uVar17 = uVar8 - (uVar11 & 0xfffffff8); (uVar17 & 0xff) != 0;
                              uVar17 = uVar17 - 1) {
                            uVar12 = uVar12 >> 1;
                          }
                          uVar11 = (uVar11 & 0xff) >> 3;
                          if ((uVar8 & 0xff) - uVar7 != 1) {
                            if (7 < uVar7) {
                              uVar7 = 8;
                            }
                            uVar7 = (iVar19 - uVar7 & 0xff) >> 3;
                            if (uVar11 != uVar7) {
                              iVar19 = 0;
                              while (iVar19 < (int)(uVar11 - uVar7)) {
                                uStack00000090 = 0;
                                iVar18 = FUN_00009fac(in_stack_0000008c + (uVar7 + iVar19 & 0xff) +
                                                      (uint)*in_stack_00000084 + 6,&stack0x00000090,
                                                      1);
                                iVar19 = iVar19 + 1;
                                if (iVar18 != 0) {
                                  return 0;
                                }
                              }
                              uVar13 = (uint)*in_stack_00000084;
                            }
                          }
                          uStack00000090 = (char)uVar12;
                          iVar18 = FUN_00009fac(in_stack_0000008c + uVar11 + uVar13 + 6,
                                                &stack0x00000090,1);
                          in_stack_00000078 = DAT_0000f7a4;
                          param_4 = DAT_0000f7a0;
                          iVar19 = DAT_0000f79c;
                          unaff_r5 = DAT_0000f798;
                          if (iVar18 != 0) {
                            return 0;
                          }
                          do {
                            in_stack_00000088 = in_stack_00000088 + 1;
                            if (in_stack_00000088 == 8) {
                              return 0;
                            }
                            uVar8 = DAT_0000f798[in_stack_00000088 * 2 & 0xff];
                            in_stack_00000070 = in_stack_00000088 * 2 + 1;
                            uVar7 = in_stack_00000070 & 0xff;
                            uVar13 = DAT_0000f798[uVar7];
                            in_stack_00000080 = (undefined4 *)(uVar8 - uVar13);
                            if (uVar8 < uVar13) {
                              in_stack_00000080 = (undefined4 *)0x0;
                            }
                          } while (uVar8 <= uVar13);
                          in_stack_0000006c = DAT_0000f798 + uVar7;
                          in_stack_00000064 = DAT_0000f79c;
                          in_stack_00000068 = DAT_0000f79c + uVar7;
                          if (0xd0 < (int)in_stack_00000080 +
                                     (uint)*(byte *)(in_stack_00000068 + 0x10)) break;
                          iVar19 = DAT_0000f7a0 + uVar7 * 2;
                          in_stack_00000084 = (ushort *)(iVar19 + 0x20);
                          if (*(ushort *)(iVar19 + 0x20) == DAT_0000f7a8) {
LAB_0000f526:
                            in_stack_0000005c = 0x26;
                            param_2 = (uint)*(byte *)(in_stack_00000078 + 0x26);
                            in_stack_00000028 = DAT_0000f7ac + 1;
                            uVar7 = param_2 * in_stack_00000028 + DAT_0000f7ac;
                            in_stack_00000060 = (uint)*(ushort *)(in_stack_00000078 + 0x32);
                            if (in_stack_00000060 <= (uVar7 & 0xffff)) goto LAB_0000f5de;
                            uVar13 = param_2 + 1;
                            *(char *)(in_stack_00000078 + 0x26) = (char)uVar13;
                            if (1 < (uVar13 & 0xff)) {
                              uVar13 = 0;
                              *(undefined1 *)(in_stack_00000078 + 0x26) = 0;
                              *(undefined2 *)(in_stack_00000078 + 0x32) = 0;
                              in_stack_00000060 = 0;
                            }
                            if ((in_stack_00000028 * (uVar13 & 0xff) + DAT_0000f7ac & 0xffff) <
                                in_stack_00000060) {
                              return 0;
                            }
                            *(short *)(in_stack_00000078 + 0x32) = (short)in_stack_00000060 + 0x20;
                            in_stack_00000024 = 0x1f;
                            uStack00000090 = 0x1f;
                            iVar19 = FUN_00009fac((uVar7 - 0x1f & 0xffff) + in_stack_0000008c,
                                                  &stack0x00000090,1);
                            if (iVar19 != 0) {
                              return 0;
                            }
                            in_stack_00000020 = 0x7f;
                            uStack00000090 = 0x7f;
                            param_7 = in_stack_00000060 + in_stack_0000008c;
                            iVar19 = FUN_00009fac(param_7,&stack0x00000090,1);
                            if (iVar19 != 0) {
                              return 0;
                            }
                            param_3 = DAT_0000f7b0 + 0x20;
                            param_1 = DAT_0000f7b0;
                            in_stack_0000001c = param_2;
                            in_stack_0000003c = param_3;
                            goto code_r0x0000f5b8;
                          }
                        }
                        uVar13 = ((int)in_stack_00000080 + uVar13) - 1;
                        *in_stack_0000006c = uVar13;
                        iVar18 = param_4 + uVar7 * 2;
                        uVar7 = (uint)*(ushort *)(iVar18 + 0x20);
                        in_stack_00000084 = (ushort *)(iVar18 + 0x20);
                        if (uVar7 == DAT_0000f7a8) {
                          in_stack_00000080 = (undefined4 *)in_stack_0000004c;
                          goto LAB_0000f526;
                        }
                        uVar8 = (uint)*(byte *)(in_stack_00000078 + 0x26);
                        iVar18 = DAT_0000f7ac + 1;
                        uVar13 = uVar8 * iVar18 + DAT_0000f7ac;
                        puStack00000074 = (undefined4 *)(uint)*(ushort *)(in_stack_00000078 + 0x32);
                        if ((uVar13 & 0xffff) < puStack00000074) goto LAB_0000f470;
                        *(ushort *)(in_stack_00000078 + 0x32) =
                             *(ushort *)(in_stack_00000078 + 0x32) + 0x20;
                        uStack00000090 = 0x1f;
                        iVar19 = FUN_00009fac(uVar7 + in_stack_0000008c,&stack0x00000090,1);
                        if (iVar19 != 0) {
                          return 0;
                        }
                        if (puStack00000074 == (undefined4 *)DAT_0000f7a8) {
                          return 0;
                        }
                        uVar13 = *in_stack_0000006c;
                        uVar1 = *in_stack_00000084;
                        in_stack_00000098 = 0x7f;
                        iVar18 = (int)puStack00000074 + in_stack_0000008c;
                        iVar19 = FUN_00009fac(iVar18,&stack0x00000098,1);
                        if (iVar19 != 0) {
                          return 0;
                        }
                        FUN_000001a0(&stack0x00000090,0xff,5);
                        in_stack_00000040[3] = (char)(uVar13 >> 0x18);
                        in_stack_00000040[2] = (char)(uVar13 >> 0x10);
                        in_stack_00000040[1] = (char)(uVar13 >> 8);
                        *in_stack_00000040 = (char)uVar13;
                        uStack00000090 = (undefined1)in_stack_00000070;
                        iVar19 = FUN_00009fac(iVar18 + 1,&stack0x00000090,5);
                        if (iVar19 != 0) {
                          return 0;
                        }
                        in_stack_00000098 = 0x3f;
                        iVar19 = FUN_00009fac(iVar18,&stack0x00000098,1);
                        if (iVar19 != 0) {
                          return 0;
                        }
                        uStack00000090 = 7;
                        in_stack_00000080 = (undefined4 *)0x1;
                        iVar19 = FUN_00009fac((uint)uVar1 + in_stack_0000008c);
                        if (iVar19 != 0) {
                          return 0;
                        }
                        *in_stack_00000084 = (ushort)puStack00000074;
                        *(undefined1 *)(in_stack_00000068 + 0x10) = 0;
                      } while( true );
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
LAB_0000f470:
  uVar7 = uVar8 + 1;
  *(char *)(in_stack_00000078 + 0x26) = (char)uVar7;
  if (1 < (uVar7 & 0xff)) {
    uVar7 = 0;
    *(undefined1 *)(in_stack_00000078 + 0x26) = 0;
    *(undefined2 *)(in_stack_00000078 + 0x32) = 0;
    puStack00000074 = (undefined4 *)0x0;
  }
  if ((iVar18 * (uVar7 & 0xff) + DAT_0000f7ac & 0xffff) < puStack00000074) {
    return 0;
  }
  *(short *)(in_stack_00000078 + 0x32) = (short)puStack00000074 + 0x20;
  uStack0000002c = 0x1f;
  uStack00000090 = 0x1f;
  iVar3 = FUN_00009fac((uVar13 - 0x1f & 0xffff) + in_stack_0000008c,&stack0x00000090,1);
  if (iVar3 != 0) {
    return 0;
  }
  uStack00000090 = 0x7f;
  iVar3 = (int)puStack00000074 + in_stack_0000008c;
  iVar4 = FUN_00009fac(iVar3,&stack0x00000090,1);
  if (iVar4 != 0) {
    return 0;
  }
  iVar4 = DAT_0000f7b0 + 0x20;
  puVar10 = (ushort *)(param_4 + 0x20);
  iVar14 = 0;
  puVar16 = DAT_0000f798;
  while( true ) {
    if (iVar14 == 0x12) {
      return 0;
    }
    if ((uVar8 * iVar4 + DAT_0000f7b0 & 0xffff) == (uint)*puVar10) break;
    puVar10 = puVar10 + 1;
    puVar16 = puVar16 + 1;
    iVar14 = iVar14 + 1;
  }
  puVar9 = (ushort *)(param_4 + 0x20);
  iVar20 = 0;
  in_stack_00000080 = DAT_0000fbc4;
  while( true ) {
    uStack00000090 = (undefined1)uStack0000002c;
    if (iVar20 == 0x12) break;
    if ((iVar14 != iVar20) && (uVar13 = (uint)*puVar9, uVar13 != DAT_0000fbbc)) {
      uVar7 = (uint)*(byte *)(in_stack_00000078 + 0x26) * iVar4;
      if ((uVar13 < (uVar7 & 0xe000)) || ((DAT_0000fbc0 + uVar7 + 0x1f & 0xffff) < uVar13)) {
        uVar1 = *(ushort *)(in_stack_00000078 + 0x32);
        uVar7 = (uint)uVar1;
        if ((iVar18 * (uint)*(byte *)(in_stack_00000078 + 0x26) + DAT_0000fbb8 & 0xffff) < uVar7) {
          return 0;
        }
        *(ushort *)(in_stack_00000078 + 0x32) = uVar1 + 0x20;
        iVar5 = FUN_00009fac(uVar13 + in_stack_0000008c,&stack0x00000090,1);
        if (iVar5 != 0) {
          return 0;
        }
        if (uVar7 == DAT_0000fbbc) {
          return 0;
        }
        uVar15 = *in_stack_00000080;
        uVar2 = *puVar9;
        iVar5 = uVar7 + in_stack_0000008c;
        in_stack_00000098 = 0x7f;
        iVar6 = FUN_00009fac(iVar5,&stack0x00000098,1);
        if (iVar6 != 0) {
          return 0;
        }
        FUN_000001a0(&stack0x00000090,0xff);
        in_stack_00000044[3] = (char)((uint)uVar15 >> 0x18);
        in_stack_00000044[2] = (char)((uint)uVar15 >> 0x10);
        in_stack_00000044[1] = (char)((uint)uVar15 >> 8);
        *in_stack_00000044 = (char)uVar15;
        uStack00000090 = (undefined1)iVar20;
        iVar6 = FUN_00009fac(iVar5 + 1,&stack0x00000090,5);
        if (iVar6 != 0) {
          return 0;
        }
        in_stack_00000098 = 0x3f;
        iVar5 = FUN_00009fac(iVar5,&stack0x00000098,1);
        if (iVar5 != 0) {
          return 0;
        }
        uStack00000090 = 7;
        iVar5 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x00000090,1);
        if (iVar5 != 0) {
          return 0;
        }
        *puVar9 = uVar1;
        *(undefined1 *)(iVar19 + iVar20 + 0x10) = 0;
      }
    }
    puVar9 = puVar9 + 1;
    in_stack_00000080 = in_stack_00000080 + 1;
    iVar20 = iVar20 + 1;
  }
  iVar18 = FUN_00009fac((uint)*puVar10 + in_stack_0000008c,&stack0x00000090,1);
  if (iVar18 != 0) {
    return 0;
  }
  uVar15 = *puVar16;
  uVar1 = *puVar10;
  in_stack_00000098 = 0x7f;
  iVar18 = FUN_00009fac(iVar3,&stack0x00000098,1);
  if (iVar18 != 0) {
    return 0;
  }
  FUN_000001a0(&stack0x00000090,0xff);
  in_stack_00000034[3] = (char)((uint)uVar15 >> 0x18);
  in_stack_00000034[2] = (char)((uint)uVar15 >> 0x10);
  in_stack_00000034[1] = (char)((uint)uVar15 >> 8);
  *in_stack_00000034 = (char)uVar15;
  uStack00000090 = (undefined1)iVar14;
  iVar18 = FUN_00009fac(iVar3 + 1,&stack0x00000090,5);
  if (iVar18 != 0) {
    return 0;
  }
  in_stack_00000098 = 0x3f;
  iVar18 = FUN_00009fac(iVar3,&stack0x00000098,1);
  if (iVar18 != 0) {
    return 0;
  }
  in_stack_00000080 = (undefined4 *)0x1;
  uStack00000090 = 7;
  iVar18 = FUN_00009fac((uint)uVar1 + in_stack_0000008c);
  if (iVar18 != 0) {
    return 0;
  }
  *puVar10 = (ushort)puStack00000074;
  *(undefined1 *)(iVar19 + iVar14 + 0x10) = 0;
  if (2 < uVar8) {
    return 0;
  }
  iVar19 = FUN_0000a020(uVar8 * iVar4 + in_stack_0000008c,iVar4);
  goto LAB_0000f648;
}

