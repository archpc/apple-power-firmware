
undefined1 * FUN_0000080c(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  if (param_1 < param_2) {
    puVar1 = param_1;
    if (param_2 < param_1 + param_3) {
      for (; param_3 != 0; param_3 = param_3 + -1) {
        *puVar1 = *param_2;
        param_2 = param_2 + 1;
        puVar1 = puVar1 + 1;
      }
    }
    else {
      FUN_00000170(param_1);
    }
  }
  else if (param_2 < param_1) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      param_1[param_3 + -1] = param_2[param_3 + -1];
    }
  }
  return param_1;
}

