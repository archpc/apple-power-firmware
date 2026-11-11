
int FUN_000001d0(int param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  code *pcVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  uint local_34;
  uint local_30;
  uint local_2c;
  int local_1c;
  byte local_18 [4];
  
  uVar5 = (uint)*param_2;
  if (uVar5 == 0) {
    local_1c = 0;
  }
  else {
    local_30 = 0x7f8000;
    local_1c = 0;
    local_34 = 0;
    do {
      if (local_34 == 0) {
        if (uVar5 != 0x25) {
          pcVar8 = *(code **)(param_1 + 8);
          pbVar6 = param_2;
          goto LAB_00000352;
        }
        local_34 = 1;
        goto switchD_0000038a_caseD_3;
      }
      switch(uVar5) {
      case 0x20:
        if ((local_34 & 0x3f) >> 4 == 0) {
          local_34 = local_34 | 0x10;
          uVar5 = 0x20;
LAB_00000362:
          local_34 = local_34 & ~uVar5;
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
        goto switchD_00000216_caseD_21;
      case 0x23:
        uVar4 = 0x80;
        goto LAB_000002b4;
      case 0x25:
        pcVar8 = *(code **)(param_1 + 8);
        pbVar6 = DAT_00000578;
LAB_00000352:
        (*pcVar8)(param_1,pbVar6,1);
        local_1c = local_1c + 1;
        goto LAB_00000438;
      case 0x2a:
        uVar4 = *param_3;
        param_3 = param_3 + 1;
        goto LAB_0000024a;
      case 0x2b:
        if (-1 < (int)(local_34 << 0x1a)) {
          local_34 = local_34 | 0x20;
          uVar5 = 0x10;
          goto LAB_00000362;
        }
        break;
      case 0x2d:
        local_34 = (local_34 & 0xfffffebf) + 0x40;
        break;
      case 0x2e:
        uVar4 = 0x80000000;
        goto LAB_000002b4;
      case 0x30:
        local_34 = local_34 | ~(local_34 << 2) & 0x100;
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
        uVar4 = 0;
        do {
          if (9 < uVar5 - 0x30) break;
          uVar4 = (uVar5 - 0x30) + uVar4 * 10;
          uVar5 = (uint)param_2[1];
          param_2 = param_2 + 1;
        } while (uVar5 != 0);
        param_2 = param_2 + -1;
LAB_0000024a:
        if ((int)local_34 < 0) {
          uVar4 = uVar4 << 0x17;
          uVar5 = 0x7f800000;
          uVar3 = DAT_00000568;
        }
        else {
          uVar4 = uVar4 << 0xf;
          uVar5 = local_30;
          uVar3 = DAT_0000056c;
        }
        local_34 = local_34 & uVar3;
        uVar4 = uVar4 & uVar5;
LAB_000002b4:
        local_34 = local_34 | uVar4;
        break;
      default:
        switch(uVar5) {
        case 99:
          uVar5 = *param_3;
          param_3 = param_3 + 1;
          pbVar6 = local_18;
          local_18[0] = (byte)uVar5;
          pcVar8 = *(code **)(param_1 + 8);
          goto LAB_00000352;
        case 100:
        case 0x69:
          uVar5 = (local_34 & 0xf) >> 1;
          if ((uVar5 == 2) || (uVar5 != 4)) {
            uVar5 = *param_3;
            param_3 = param_3 + 1;
          }
          else {
            param_3 = (uint *)((int)param_3 + 7U & 0xfffffff8);
            uVar5 = *param_3;
            param_3 = param_3 + 2;
          }
          uVar4 = local_34 & DAT_00000570 | 0x2800;
          uVar7 = DAT_0000058c;
          if (-1 < (int)uVar5) {
            uVar3 = (local_34 & 0x3f) >> 4;
            uVar7 = DAT_00000590;
            if (uVar3 != 2) {
              uVar7 = 0;
            }
            if (uVar3 == 1) {
              uVar7 = DAT_0000057c;
            }
          }
          uVar5 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
          goto LAB_0000042c;
        case 0x68:
          local_34 = local_34 | 2;
          uVar5 = 0xc;
          goto LAB_00000362;
        case 0x6c:
          if ((local_34 & 0xe) == 4) {
            uVar5 = 8;
          }
          else {
            uVar5 = 4;
          }
          local_34 = local_34 & 0xfffffff1 | uVar5;
          break;
        case 0x6e:
          piVar2 = (int *)*param_3;
          param_3 = param_3 + 1;
          uVar5 = local_34 & 0xf;
          local_34 = 0;
          switch(uVar5 >> 1) {
          case 0:
          case 2:
            *piVar2 = local_1c;
            break;
          case 1:
            *(short *)piVar2 = (short)local_1c;
            break;
          case 4:
            *piVar2 = local_1c;
            piVar2[1] = local_1c >> 0x1f;
          }
          break;
        case 0x6f:
        case 0x75:
        case 0x78:
switchD_0000026e_caseD_6f:
          uVar4 = (local_34 & DAT_00000570 & 0xf) >> 1;
          if ((uVar4 == 2) || (uVar4 != 4)) {
            uVar4 = *param_3;
            param_3 = param_3 + 1;
          }
          else {
            param_3 = (uint *)((int)param_3 + 7U & 0xfffffff8);
            uVar4 = *param_3;
            param_3 = param_3 + 2;
          }
          uVar7 = 0;
          if (((((int)((local_34 & DAT_00000570) << 0x18) < 0) && (uVar7 = 0, uVar4 != 0)) &&
              (uVar7 = DAT_00000584, uVar5 != 0x58)) &&
             ((uVar7 = DAT_00000588, uVar5 != 0x6f && (uVar7 = DAT_00000580, uVar5 != 0x78)))) {
            uVar7 = 0;
          }
          iVar1 = FUN_00000594(param_1,uVar4,uVar7);
          local_1c = iVar1 + local_1c;
          local_34 = 0;
          break;
        case 0x70:
          uVar4 = local_34 & DAT_00000570 | 0x4000;
          uVar5 = *param_3;
          param_3 = param_3 + 1;
          uVar7 = DAT_00000580;
LAB_0000042c:
          iVar1 = FUN_00000594(param_1,uVar5,uVar7,uVar4);
          goto LAB_00000432;
        case 0x73:
          uVar4 = local_34 & 0x40;
          pcVar11 = (char *)*param_3;
          param_3 = param_3 + 1;
          uVar5 = local_34 >> 0xf & 0xff;
          if ((uVar5 == 0) || (uVar4 != 0)) {
            local_2c = local_34 >> 0x17 & 0xff;
          }
          else {
            if (*pcVar11 == '\0') {
              uVar3 = 0;
            }
            else {
              uVar3 = 0;
              do {
                iVar1 = uVar3 + 1;
                uVar3 = uVar3 + 1;
              } while (pcVar11[iVar1] != '\0');
            }
            local_2c = local_34 >> 0x17 & 0xff;
            uVar9 = local_2c;
            if ((int)uVar3 <= (int)local_2c) {
              uVar9 = uVar3;
            }
            if (-1 < (int)local_34) {
              uVar9 = uVar3;
            }
            if ((int)uVar9 < (int)uVar5) {
              iVar1 = uVar5 - uVar9;
              do {
                (**(code **)(param_1 + 8))(param_1,DAT_0000057c,1);
                iVar1 = iVar1 + -1;
              } while (iVar1 != 0);
              local_1c = (local_1c + uVar5) - uVar9;
            }
          }
          if (*pcVar11 == '\0') {
            uVar3 = 0;
          }
          else {
            uVar3 = 0;
            do {
              if ((int)local_34 < 0 && local_2c <= uVar3) break;
              pcVar10 = pcVar11 + uVar3;
              (**(code **)(param_1 + 8))(param_1,pcVar10,1);
              uVar3 = uVar3 + 1;
            } while (pcVar10[1] != '\0');
            local_1c = local_1c + uVar3;
          }
          local_34 = 0;
          if ((uVar5 != 0 && uVar4 != 0) && (uVar3 < uVar5)) {
            local_34 = 0;
            iVar1 = uVar5 - uVar3;
            do {
              (**(code **)(param_1 + 8))(param_1,DAT_0000057c,1);
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
            local_1c = (local_1c + uVar5) - uVar3;
          }
          break;
        default:
          if (uVar5 == 0x58) goto switchD_0000026e_caseD_6f;
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
switchD_00000216_caseD_21:
          iVar1 = FUN_00001444(DAT_00000574);
LAB_00000432:
          local_1c = iVar1 + local_1c;
LAB_00000438:
          local_34 = 0;
        }
      }
switchD_0000038a_caseD_3:
      uVar5 = (uint)param_2[1];
      param_2 = param_2 + 1;
    } while (uVar5 != 0);
  }
  return local_1c;
}

