
void FUN_0000c640(int param_1,int param_2,code *param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  cVar2 = *(char *)(DAT_0000c770 + 0x21);
  if (cVar2 != '\x02') {
    if (param_4 == 0) {
      uVar4 = *(uint *)(param_2 + 8) & 0xf;
      if (uVar4 != 0) {
        if (uVar4 == 5) {
          uVar5 = 0;
          goto LAB_0000c69a;
        }
        if (cVar2 != '\x01') {
          bVar1 = *(byte *)(param_2 + 1);
          iVar3 = param_1 * 0x30 + DAT_0000c774;
          for (iVar6 = 0; (uint)bVar1 * 4 - iVar6 != 0; iVar6 = iVar6 + 4) {
            *(undefined4 *)(iVar3 + 0xc + iVar6) = *(undefined4 *)(param_2 + iVar6 + 8);
          }
          if (uVar4 != 1) {
            if (uVar4 != 2) {
              return;
            }
            if (*(char *)(iVar3 + 10) != '\x02') {
              *(undefined1 *)(iVar3 + 0x29) = 1;
              *(byte *)(iVar3 + 0x28) = bVar1;
              FUN_0000c3f8(param_1,(uint)bVar1,5,0);
            }
            (*param_3)(param_1);
            return;
          }
          uVar5 = 0;
          goto LAB_0000c73e;
        }
        goto LAB_0000c716;
      }
      if (*(char *)(DAT_0000c774 + (uint)(param_1 != 1) * 0x30 + 10) == '\x01') {
        uVar5 = 0;
        goto LAB_0000c6f6;
      }
    }
    else {
      uVar4 = *(uint *)(param_2 + 0xc) & 0xf;
      if (uVar4 != 0) {
        if (uVar4 != 2) {
          if (uVar4 != 5) {
            return;
          }
          uVar5 = 1;
LAB_0000c69a:
          FUN_0000c778(param_1,param_2,param_3,uVar5);
          return;
        }
        if (cVar2 != '\x01') {
          uVar5 = 1;
LAB_0000c73e:
          FUN_0000c834(param_1,param_2,param_3,uVar5);
          return;
        }
        goto LAB_0000c716;
      }
      if (*(char *)(DAT_0000c774 + (uint)(param_1 != 1) * 0x30 + 10) == '\x01') {
        uVar5 = 1;
LAB_0000c6f6:
        FUN_0000c804(param_1,param_3,uVar5);
        return;
      }
    }
    *(undefined1 *)(DAT_0000c770 + 0x21) = 2;
  }
LAB_0000c716:
  FUN_0000c5f8(param_1,param_1 != 1,param_2,param_3);
  return;
}

