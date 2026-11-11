
void FUN_00002f6c(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined1 auStack_50 [60];
  
  iVar3 = DAT_00002fd0 + param_1 * 0x1cc;
  *(undefined1 *)(iVar3 + 0x1c9) = 0;
  if (*(char *)(iVar3 + 0x2f) == '\x01') {
    pcVar2 = *(code **)(iVar3 + 100);
    if (param_2 != 3) {
      *(undefined1 *)(iVar3 + 0x2f) = 0;
    }
    if (pcVar2 != (code *)0x0) {
      if (param_3 == 0) {
        puVar1 = (undefined1 *)0x0;
      }
      else {
        puVar1 = auStack_50;
        FUN_00000170(puVar1,param_3,0x3c);
      }
      (*pcVar2)(param_1,param_2,puVar1);
      if (param_2 != 3) {
        *(undefined4 *)(iVar3 + 100) = 0;
      }
    }
  }
  return;
}

