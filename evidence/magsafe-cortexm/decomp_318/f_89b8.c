
void FUN_000089b8(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  int iVar7;
  
  iVar7 = *(int *)(DAT_00008aa8 + param_1 * 4);
  *(uint *)(iVar7 + 0x128) = *(uint *)(iVar7 + 0x128) & 0xffffdfff;
  *(undefined4 *)(iVar7 + 0x118) = DAT_00008aa0;
  iVar2 = DAT_00008aac;
  iVar4 = DAT_00008aac + param_1 * 0x5c;
  if (*(char *)(iVar4 + 0x53) < '\0') {
    *(uint *)(iVar7 + 0x120) = *(uint *)(iVar7 + 0x120) | 0x4000;
  }
  else {
    puVar5 = (uint *)(iVar7 + 0x128);
    pcVar6 = (char *)(iVar4 + 0x53);
    if ((*(uint *)(iVar7 + 0xa4) & 0x100001) == 0) {
      *(undefined1 *)(iVar4 + 0x51) = 0;
      iVar2 = FUN_000082ec(param_1);
      if (iVar2 != 0) {
        *puVar5 = *puVar5 | 0x100000;
      }
      *puVar5 = DAT_00008aa4 | *puVar5;
      *(uint *)(iVar7 + 4) =
           (*(uint *)(iVar7 + 4) & 0xfffffffd) + (uint)(*(char *)(iVar4 + 0x52) == '\x01') * 2;
      uVar3 = *(uint *)(iVar7 + 0xf4);
      cVar1 = *pcVar6;
      *(undefined1 *)(iVar4 + 0x54) = 0;
      *pcVar6 = *pcVar6 + -1;
      *(uint *)(iVar7 + 0xf4) = (uVar3 & 0xfff5ffff) + (uint)(cVar1 != '\0') * 0x80000 + 0x20000;
    }
    else {
      *pcVar6 = *pcVar6 + -1;
      *puVar5 = *puVar5 | 0x2000;
      (**(code **)(iVar2 + param_1 * 0x5c))(param_1,0);
    }
  }
  return;
}

