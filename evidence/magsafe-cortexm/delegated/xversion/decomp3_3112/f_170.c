
void FUN_00000170(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((((uint)param_1 & 3) == 0) && ((((uint)param_2 | param_3) & 3) == 0)) {
    for (param_3 = param_3 >> 2; param_3 != 0; param_3 = param_3 - 1) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
  }
  return;
}

