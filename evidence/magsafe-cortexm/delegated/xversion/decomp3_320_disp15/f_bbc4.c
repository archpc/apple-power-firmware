
char FUN_0000bbc4(int param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  char local_18 [4];
  
  local_18[0] = '\0';
  iVar1 = *(int *)(param_1 + 8);
  if ((param_3 == 0) || (*(int *)(param_1 + 0x10) != param_2)) {
    (**(code **)(iVar1 + 0xc))(param_1,param_2,param_3,local_18);
    if (local_18[0] == '\0') {
      return '\0';
    }
    *(int *)(param_1 + 4) = iVar1;
  }
  else {
    *(int *)(param_1 + 8) = param_3;
    local_18[0] = '\x01';
    *(int *)(param_1 + 4) = iVar1;
    if (iVar1 == 0) goto LAB_0000bc20;
  }
  if (*(code **)(iVar1 + 8) != (code *)0x0) {
    (**(code **)(iVar1 + 8))(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0xc));
  }
LAB_0000bc20:
  pcVar2 = *(code **)(*(int *)(param_1 + 8) + 4);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0xc));
  }
  return local_18[0];
}

