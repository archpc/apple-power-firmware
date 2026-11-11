
/* WARNING: Removing unreachable block (ram,0x00005696) */
/* WARNING: Removing unreachable block (ram,0x000057c0) */
/* WARNING: Removing unreachable block (ram,0x000057e8) */

void FUN_000050fc(code *param_1,int param_2)

{
  code *pcVar1;
  code cVar2;
  code cVar3;
  undefined2 uVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  undefined **ppuVar8;
  undefined4 uVar9;
  uint uVar10;
  code *pcVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  
  pcVar11 = (code *)(DAT_0000547c + (int)param_1 * 0xf0);
  cVar2 = pcVar11[0xac];
  puVar13 = (undefined4 *)(uint)(byte)pcVar11[0xab];
  puVar12 = (undefined4 *)(uint)(byte)pcVar11[0xaa];
  uVar4 = *(undefined2 *)(pcVar11 + 0xae);
  uVar14 = *(uint *)(pcVar11 + 0xb4);
  cVar3 = pcVar11[0xad];
  uVar10 = DAT_00005480 + (int)param_1 * 0x1cc;
  if ((param_2 == 2) && (*(char *)(uVar10 + 0x10) != '\x02')) {
    if (((int)puVar12 - 1U & 0xff) < 2) {
      if (*(byte *)(uVar10 + 0x3e) < 2) {
        if (*(char *)(uVar10 + 0x14) == '\x01') {
LAB_00005222:
          if (puVar13 == (undefined4 *)0x2) {
            FUN_00007272(param_1,puVar12,cVar2,uVar4);
            return;
          }
          if (puVar13 != (undefined4 *)0x1) {
            if (puVar13 != (undefined4 *)0x0) {
              return;
            }
            FUN_00006ec8(param_1,puVar12,cVar2);
            return;
          }
          FUN_00007260(param_1,puVar12,cVar2,cVar3);
          return;
        }
      }
      else if ((*(char *)(uVar10 + 0x28) != '\0') &&
              (iVar7 = (**(code **)(*(int *)(uVar10 + 0x60) + 0x1c))(param_1), iVar7 != 0))
      goto LAB_00005222;
      FUN_0000301a(param_1,1);
      FUN_00003258(param_1,0x23);
      return;
    }
    if ((undefined4 *)0x3 < puVar13) {
      return;
    }
    pcVar6 = (code *)(&PTR_LAB_000051f8)[(int)puVar13];
    switch(puVar13) {
    case (undefined4 *)0x0:
      if (pcVar11 < (code *)0x2) {
        pcVar6 = (code *)((int)pcVar11 * 0x1cc);
        goto LAB_000056ba;
      }
      break;
    case (undefined4 *)0x1:
      goto LAB_000056ca;
    case (undefined4 *)0x2:
LAB_000056ba:
      pcVar6 = DAT_000057a8 + (int)pcVar6;
      ppuVar8 = (undefined **)0x175;
      goto code_r0x000056c2;
    case (undefined4 *)0x3:
      *(code **)(uVar14 + 0x1c) = param_1;
      return;
    }
LAB_000056c6:
    pcVar6 = (code *)0x1cc;
LAB_000056ca:
    pcVar6 = DAT_000057a8 + (int)pcVar11 * (int)pcVar6;
    goto code_r0x000056d0;
  }
  uVar5 = param_2 - 2;
  if (0xc < uVar5) {
    return;
  }
  iVar7 = uVar5 * 4;
  ppuVar8 = &PTR_FUN_00005168;
  pcVar6 = (code *)(&PTR_FUN_00005168)[uVar5];
  switch(param_2) {
  case 2:
    ppuVar8 = &PTR_FUN_00005168;
    pcVar1 = pcVar6 + 4;
    bVar16 = false;
    pcVar6 = (code *)((uint)(byte)*pcVar1 * 2);
    bVar15 = (byte)*pcVar1 == 0;
    switch(pcVar6 + 0x56aa) {
    case (code *)0x56c2:
code_r0x000056c2:
      pcVar6[(int)ppuVar8] = (code)0x0;
      goto LAB_000056c6;
    case (code *)0x56ca:
      goto LAB_000056ca;
    case (code *)0x56d0:
      goto code_r0x000056d0;
    case (code *)0x56fa:
      goto code_r0x000056fa;
    case (code *)0x572c:
      if (uVar14 >> 0x18 != 4) {
        if (uVar14 >> 0x18 != 2) {
          FUN_0000ca08(pcVar11,0xc);
          pcVar6 = pcVar11;
          goto FUN_00005752;
        }
        uVar9 = 0x2c;
        goto code_r0x0000579c;
      }
      param_1 = DAT_000057a8;
      if (pcVar11 < (code *)0x2) {
        pcVar6 = DAT_000057a8 + (int)pcVar11 * 0x1cc;
        ppuVar8 = (undefined **)0x175;
        goto FUN_0000576a;
      }
      goto code_r0x0000576e;
    case (code *)0x57b8:
      return;
    case (code *)0x57ee:
      iVar7 = FUN_00005c68(pcVar6,&PTR_FUN_00005168);
      if (iVar7 == 0) {
        if (*(char *)*puVar13 == '\x01') {
          FUN_00005c8c(pcVar11);
          return;
        }
        break;
      }
      pcVar6 = (code *)((*(uint *)((char *)*puVar13 + 8) >> 0x18) - 2);
      bVar16 = (code *)0x2 < pcVar6;
      bVar15 = pcVar6 == (code *)0x3;
    case (code *)0x5800:
      if (!bVar16 || bVar15) {
                    /* WARNING: Could not recover jumptable at 0x0000580a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((uint)(byte)pcVar6[0x580c] * 2 + 0x580e))();
        return;
      }
      break;
    case (code *)0x58a4:
      ppuVar8 = (undefined **)0x3e;
    case (code *)0x58a6:
      (*param_1)(pcVar11,ppuVar8);
      if ((uVar14 & 0xff0000) == (int)puVar12 * 0x40000) {
        uVar9 = 0x23;
code_r0x0000586e:
        FUN_00003258(pcVar11,uVar9);
        return;
      }
    }
LAB_000058ea:
    FUN_00005b5c(pcVar11);
    return;
  case 3:
    return;
  case 4:
    goto FUN_000056da;
  case 5:
    goto FUN_000056ee;
  case 6:
    FUN_000030f0(pcVar11,0xc);
    return;
  default:
    goto FUN_00005704;
  case 8:
    goto FUN_00005752;
  case 0xb:
FUN_0000576a:
    pcVar6[(int)ppuVar8] = (code)0x0;
code_r0x0000576e:
    FUN_0000ca08(pcVar11,0xc);
    (*(code *)**(undefined4 **)(param_1 + (int)pcVar11 * 0x1cc + 0x60))(pcVar11,0x3e,*puVar12);
    pcVar6 = pcVar11;
    if ((uVar14 & 0xff0000) != (int)puVar13 * 0x40000) {
FUN_00005752:
      FUN_00005b5c(pcVar6);
      return;
    }
    break;
  case 0xe:
    if (iVar7 == 0) {
      if (pcVar11 < (code *)0x2) {
        *(undefined1 *)(DAT_000058f8 + (int)pcVar11 * 0x1cc + 0x175) = 1;
      }
      FUN_0000ca08(pcVar11,0xc);
      (*(code *)**(undefined4 **)(DAT_000058f8 + (int)pcVar11 * 0x1cc + 0x60))(pcVar11,0x3d,0);
      uVar9 = 0xb;
      goto code_r0x0000586e;
    }
    if (pcVar6 != (code *)((int)&Reset + 1)) {
      return;
    }
    if (pcVar11 < (code *)0x2) {
      *(undefined1 *)(DAT_000058f8 + (int)pcVar11 * 0x1cc + 0x175) = 0;
    }
    goto LAB_000058ea;
  }
  goto LAB_0000579a;
code_r0x000056d0:
  iVar7 = (uint)*(byte *)(*(int *)(pcVar6 + 0x11c) + 10) << 0x18;
FUN_000056da:
  if ((iVar7 < 0) && (pcVar6[0x1a1] != (code)0x0)) {
    ppuVar8 = (undefined **)0xe8;
    uVar10 = (uint)*(ushort *)(puVar12 + 0x3a);
    param_1 = (code *)0x172;
FUN_000056ee:
    pcVar6 = (code *)(uVar10 + (uint)(byte)pcVar6[(int)param_1] * 0x10000 + 0x1000000);
code_r0x000056fa:
    *(code **)((int)puVar12 + (int)ppuVar8) = pcVar6;
    ppuVar8 = (undefined **)0x0;
    uVar10 = 10;
FUN_00005704:
    FUN_00007260(pcVar11,ppuVar8,uVar10);
    return;
  }
LAB_0000579a:
  uVar9 = 0x23;
code_r0x0000579c:
  FUN_00003258(pcVar11,uVar9);
  return;
}

