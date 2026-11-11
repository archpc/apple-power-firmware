
void FUN_0000c49c(int param_1,int param_2,code *param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  cVar1 = *(char *)(DAT_0000c5b0 + 0x19);
  if (cVar1 != '\x02') {
    if (param_4 == 0) {
      uVar5 = *(uint *)(param_2 + 8) & 0xf;
      if (uVar5 != 0) {
        if (uVar5 == 5) {
          uVar6 = 0;
          goto LAB_0000c4e4;
        }
        if (cVar1 != '\x01') {
          bVar2 = *(byte *)(param_2 + 1);
          iVar4 = DAT_0000c5b4 + param_1 * 0x30;
          for (iVar3 = 0; (uint)bVar2 * 4 - iVar3 != 0; iVar3 = iVar3 + 4) {
            *(undefined4 *)(iVar4 + 0xc + iVar3) = *(undefined4 *)(param_2 + iVar3 + 8);
          }
          if (uVar5 != 1) {
            if (uVar5 != 2) {
              return;
            }
            if (*(char *)(iVar4 + 10) != '\x02') {
              *(undefined1 *)(iVar4 + 0x29) = 1;
              *(byte *)(iVar4 + 0x28) = bVar2;
              FUN_0000c254(param_1,iVar4,5,0);
            }
            (*param_3)(param_1);
            return;
          }
          uVar6 = 0;
          goto LAB_0000c57c;
        }
        goto LAB_0000c558;
      }
      if (*(char *)(DAT_0000c5b4 + (uint)(param_1 != 1) * 0x30 + 10) == '\x01') {
        uVar6 = 0;
        goto LAB_0000c540;
      }
    }
    else {
      uVar5 = *(uint *)(param_2 + 0xc) & 0xf;
      if (uVar5 != 0) {
        if (uVar5 != 2) {
          if (uVar5 != 5) {
            return;
          }
          uVar6 = 1;
LAB_0000c4e4:
          FUN_0000c5b8(param_1,param_2,param_3,uVar6);
          return;
        }
        if (cVar1 != '\x01') {
          uVar6 = 1;
LAB_0000c57c:
          FUN_0000c674(param_1,param_2,param_3,uVar6);
          return;
        }
        goto LAB_0000c558;
      }
      if (*(char *)(DAT_0000c5b4 + (uint)(param_1 != 1) * 0x30 + 10) == '\x01') {
        uVar6 = 1;
LAB_0000c540:
        FUN_0000c644(param_1,param_3,uVar6);
        return;
      }
    }
    *(undefined1 *)(DAT_0000c5b0 + 0x19) = 2;
  }
LAB_0000c558:
  FUN_0000c454(param_1,param_1 != 1,param_2,param_3);
  return;
}

