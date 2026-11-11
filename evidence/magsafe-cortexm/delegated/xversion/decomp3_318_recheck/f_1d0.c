
int FUN_000001d0(int param_1,byte *param_2,uint *param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 uVar8;
  uint uVar9;
  code *pcVar10;
  char *pcVar11;
  char *pcVar12;
  uint local_2c;
  uint local_24;
  int local_1c;
  byte local_18 [4];
  
  uVar6 = (uint)*param_2;
  if (uVar6 == 0) {
    local_1c = 0;
  }
  else {
    local_24 = 1;
    local_1c = 0;
    uVar9 = 0;
    do {
      if (uVar9 == 0) {
        uVar9 = local_24;
        if (uVar6 != 0x25) {
          pcVar10 = *(code **)(param_1 + 8);
          pbVar7 = param_2;
          goto LAB_00000348;
        }
        goto switchD_00000382_caseD_3;
      }
      switch(uVar6) {
      case 0x20:
        if ((uVar9 & 0x3f) >> 4 == 0) {
          uVar9 = uVar9 | 0x10;
          uVar6 = 0x20;
LAB_00000358:
          uVar9 = uVar9 & ~uVar6;
        }
        break;
      case 0x21:
      case 0x22:
      case 0x24:
      case 0x26:
      case 0x27:
      case 0x28:
      case 0x29:
      case 0x2c:
      case 0x2f:
        goto switchD_0000020e_caseD_21;
      case 0x23:
        uVar6 = 0x80;
        goto LAB_0000032c;
      case 0x25:
        pcVar10 = *(code **)(param_1 + 8);
        pbVar7 = DAT_00000548;
LAB_00000348:
        (*pcVar10)(param_1,pbVar7,1);
        local_1c = local_1c + 1;
        goto LAB_00000432;
      case 0x2a:
        bVar1 = (byte)*param_3;
        param_3 = param_3 + 1;
        goto LAB_00000244;
      case 0x2b:
        if (-1 < (int)(uVar9 << 0x1a)) {
          uVar9 = uVar9 | 0x20;
          uVar6 = 0x10;
          goto LAB_00000358;
        }
        break;
      case 0x2d:
        uVar9 = (uVar9 & 0xfffffebf) + 0x40;
        break;
      case 0x2e:
        uVar6 = 0x80000000;
        goto LAB_0000032c;
      case 0x30:
        uVar9 = uVar9 | ~(uVar9 << 2) & 0x100;
        break;
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
        iVar2 = 0;
        do {
          bVar1 = (byte)iVar2;
          if (9 < uVar6 - 0x30) break;
          iVar2 = (uVar6 - 0x30) + iVar2 * 10;
          bVar1 = (byte)iVar2;
          uVar6 = (uint)param_2[1];
          param_2 = param_2 + 1;
        } while (uVar6 != 0);
        param_2 = param_2 + -1;
LAB_00000244:
        if ((int)uVar9 < 0) {
          uVar9 = uVar9 & DAT_00000538;
          uVar6 = (uint)bVar1 << 0x17;
        }
        else {
          uVar9 = uVar9 & DAT_0000053c;
          uVar6 = (uint)bVar1 << 0xf;
        }
LAB_0000032c:
        uVar9 = uVar9 | uVar6;
        break;
      default:
        switch(uVar6) {
        case 99:
          uVar6 = *param_3;
          param_3 = param_3 + 1;
          pbVar7 = local_18;
          local_18[0] = (byte)uVar6;
          pcVar10 = *(code **)(param_1 + 8);
          goto LAB_00000348;
        case 100:
        case 0x69:
          uVar6 = (uVar9 & 0xf) >> 1;
          if ((uVar6 == 2) || (uVar6 != 4)) {
            uVar6 = *param_3;
            param_3 = param_3 + 1;
          }
          else {
            param_3 = (uint *)((uint)((int)param_3 + 7) & 0xfffffff8);
            uVar6 = *param_3;
            param_3 = param_3 + 2;
          }
          uVar4 = uVar9 & DAT_00000540 | 0x2800;
          uVar8 = DAT_0000055c;
          if (-1 < (int)uVar6) {
            uVar9 = (uVar9 & 0x3f) >> 4;
            uVar8 = DAT_00000560;
            if (uVar9 != 2) {
              uVar8 = 0;
            }
            if (uVar9 == 1) {
              uVar8 = DAT_0000054c;
            }
          }
          uVar6 = uVar6 + ((int)uVar6 >> 0x1f) ^ (int)uVar6 >> 0x1f;
          goto LAB_00000426;
        case 0x68:
          uVar9 = uVar9 | 2;
          uVar6 = 0xc;
          goto LAB_00000358;
        case 0x6c:
          if ((uVar9 & 0xe) == 4) {
            uVar6 = 8;
          }
          else {
            uVar6 = 4;
          }
          uVar9 = uVar9 & 0xfffffff1 | uVar6;
          break;
        case 0x6e:
          piVar3 = (int *)*param_3;
          param_3 = param_3 + 1;
          uVar6 = uVar9 & 0xf;
          uVar9 = 0;
          switch(uVar6 >> 1) {
          case 0:
          case 2:
            *piVar3 = local_1c;
            break;
          case 1:
            *(short *)piVar3 = (short)local_1c;
            break;
          case 4:
            *piVar3 = local_1c;
            piVar3[1] = local_1c >> 0x1f;
          }
          break;
        case 0x6f:
        case 0x75:
        case 0x78:
switchD_00000266_caseD_6f:
          uVar4 = (uVar9 & DAT_00000540 & 0xf) >> 1;
          if ((uVar4 == 2) || (uVar4 != 4)) {
            uVar4 = *param_3;
            param_3 = param_3 + 1;
          }
          else {
            param_3 = (uint *)((uint)((int)param_3 + 7) & 0xfffffff8);
            uVar4 = *param_3;
            param_3 = param_3 + 2;
          }
          uVar8 = 0;
          if ((((int)((uVar9 & DAT_00000540) << 0x18) < 0) && (uVar8 = 0, uVar4 != 0)) &&
             ((uVar8 = DAT_00000554, uVar6 != 0x58 &&
              ((uVar8 = DAT_00000558, uVar6 != 0x6f && (uVar8 = DAT_00000550, uVar6 != 0x78)))))) {
            uVar8 = 0;
          }
          iVar2 = FUN_00000564(param_1,uVar4,uVar8);
          local_1c = iVar2 + local_1c;
          uVar9 = 0;
          break;
        case 0x70:
          uVar4 = uVar9 & DAT_00000540 | 0x4000;
          uVar6 = *param_3;
          param_3 = param_3 + 1;
          uVar8 = DAT_00000550;
LAB_00000426:
          iVar2 = FUN_00000564(param_1,uVar6,uVar8,uVar4);
          goto LAB_0000042c;
        case 0x73:
          pcVar12 = (char *)*param_3;
          param_3 = param_3 + 1;
          uVar6 = uVar9 >> 0xf & 0xff;
          if (((uVar9 & 0x40) == 0) && (uVar6 != 0)) {
            if (*pcVar12 == '\0') {
              uVar4 = 0;
            }
            else {
              uVar4 = 0;
              do {
                iVar2 = uVar4 + 1;
                uVar4 = uVar4 + 1;
              } while (pcVar12[iVar2] != '\0');
            }
            local_2c = uVar9 >> 0x17 & 0xff;
            uVar5 = local_2c;
            if ((int)uVar4 <= (int)local_2c) {
              uVar5 = uVar4;
            }
            if ((int)uVar9 < 0) {
              uVar4 = uVar5;
            }
            if ((int)uVar4 < (int)uVar6) {
              iVar2 = uVar6 - uVar4;
              do {
                (**(code **)(param_1 + 8))(param_1,DAT_0000054c,1);
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              local_1c = (local_1c + uVar6) - uVar4;
            }
          }
          else {
            local_2c = uVar9 >> 0x17 & 0xff;
          }
          uVar4 = 0;
          if (*pcVar12 != '\0') {
            uVar4 = 0;
            do {
              if (((int)uVar9 < 0) && (local_2c <= uVar4)) break;
              pcVar11 = pcVar12 + uVar4;
              (**(code **)(param_1 + 8))(param_1,pcVar11,1);
              uVar4 = uVar4 + 1;
            } while (pcVar11[1] != '\0');
            local_1c = local_1c + uVar4;
          }
          if (((uVar4 < uVar6) && ((uVar9 & 0x40) != 0)) && (uVar6 != 0)) {
            iVar2 = uVar6 - uVar4;
            do {
              (**(code **)(param_1 + 8))(param_1,DAT_0000054c,1);
              iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
            local_1c = (local_1c + uVar6) - uVar4;
          }
          uVar9 = 0;
          break;
        default:
          if (uVar6 == 0x58) goto switchD_00000266_caseD_6f;
        case 0x65:
        case 0x66:
        case 0x67:
        case 0x6a:
        case 0x6b:
        case 0x6d:
        case 0x71:
        case 0x72:
        case 0x74:
        case 0x76:
        case 0x77:
switchD_0000020e_caseD_21:
          iVar2 = FUN_00001498(DAT_00000544);
LAB_0000042c:
          local_1c = iVar2 + local_1c;
LAB_00000432:
          uVar9 = 0;
        }
      }
switchD_00000382_caseD_3:
      uVar6 = (uint)param_2[1];
      param_2 = param_2 + 1;
    } while (uVar6 != 0);
  }
  return local_1c;
}

