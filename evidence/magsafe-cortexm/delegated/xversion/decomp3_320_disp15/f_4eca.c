
/* WARNING: Removing unreachable block (ram,0x00005560) */

void FUN_00004eca(int *param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  uint *unaff_r5;
  ushort *unaff_r6;
  int unaff_r7;
  undefined4 in_cr5;
  undefined4 in_cr9;
  undefined4 in_cr14;
  int in_stack_00000020;
  
  uVar1 = (uint)*(byte *)(*param_1 + 1);
  if (0xe < uVar1 - 3) {
    FUN_00006328();
    return;
  }
  puVar3 = (&switchD_00004ee2::switchdataD_00004ee4)[uVar1 - 3];
  switch(uVar1) {
  default:
    goto switchD_00004ee2_caseD_5;
  case 6:
    coprocessor_function2(0,9,1,in_cr14,in_cr5,in_cr9);
    unaff_r6 = (ushort *)(DAT_000055ec + 0x398);
    puVar3 = (undefined *)0xff;
  case 0x10:
    uVar1 = (uint)*(byte *)((int)unaff_r6 + (int)(puVar3 + 0x76));
switchD_00004ee2_caseD_11:
    if (uVar1 == 0) {
      FUN_00005b5c(2);
    }
    else {
      uVar1 = 2;
switchD_00004ee2_caseD_5:
      FUN_0000b9dc(uVar1);
      if (*(int *)(unaff_r6 + 0x84) < 0) {
        FUN_00003140(2);
      }
      else {
        FUN_0000ca08(2,0xd);
      }
    }
    if (DAT_000055e4 + 1U <= *unaff_r5) {
      FUN_00007260(2,0,10,1);
      return;
    }
    return;
  case 8:
  case 9:
    *(undefined1 *)(in_stack_00000020 + 0x2f) = 0;
    *(undefined4 *)(in_stack_00000020 + 100) = 0;
    FUN_00003258();
    return;
  case 10:
  case 0xb:
    uVar1 = 0x398;
  case 3:
    param_4 = *(code **)(*(int *)(DAT_000055ec + uVar1 + 0x60) + 0x70);
    unaff_r5 = (uint *)0x3;
    uVar1 = 2;
  case 4:
    iVar2 = (*param_4)(uVar1);
    if (iVar2 == 0) {
      iVar2 = unaff_r7 << 0x1a;
    }
    else {
      iVar2 = (int)unaff_r5 << 0x18;
    }
    *(uint *)unaff_r6 = (uint)*unaff_r6 + iVar2;
    return;
  case 0x11:
    goto switchD_00004ee2_caseD_11;
  }
}

