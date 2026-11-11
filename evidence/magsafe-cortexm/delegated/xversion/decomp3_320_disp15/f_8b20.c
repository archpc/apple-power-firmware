
void FUN_00008b20(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  
  iVar6 = *(int *)(DAT_00008bf8 + param_1 * 4);
  *(uint *)(iVar6 + 0x128) = *(uint *)(iVar6 + 0x128) & 0xffffdfff;
  *(undefined4 *)(iVar6 + 0x118) = DAT_00008bf0;
  puVar5 = (undefined4 *)(DAT_00008bfc + param_1 * 0x5c);
  if (*(char *)((int)puVar5 + 0x53) < '\0') {
    *(uint *)(iVar6 + 0x120) = *(uint *)(iVar6 + 0x120) | 0x4000;
  }
  else {
    puVar4 = (uint *)(iVar6 + 0x128);
    pcVar7 = (char *)((int)puVar5 + 0x53);
    if ((*(uint *)(iVar6 + 0xa4) & 0x100001) == 0) {
      *(undefined1 *)((int)puVar5 + 0x51) = 0;
      iVar2 = FUN_0000843c();
      if (iVar2 != 0) {
        *puVar4 = *puVar4 | 0x100000;
      }
      *puVar4 = DAT_00008bf4 | *puVar4;
      *(uint *)(iVar6 + 4) =
           (*(uint *)(iVar6 + 4) & 0xfffffffd) + (uint)(*(char *)((int)puVar5 + 0x52) == '\x01') * 2
      ;
      uVar3 = *(uint *)(iVar6 + 0xf4);
      cVar1 = *pcVar7;
      *(undefined1 *)(puVar5 + 0x15) = 0;
      *pcVar7 = *pcVar7 + -1;
      *(uint *)(iVar6 + 0xf4) = (uVar3 & 0xfff5ffff) + (uint)(cVar1 != '\0') * 0x80000 + 0x20000;
    }
    else {
      *pcVar7 = *pcVar7 + -1;
      *puVar4 = *puVar4 | 0x2000;
      (*(code *)*puVar5)(param_1,0);
    }
  }
  return;
}

