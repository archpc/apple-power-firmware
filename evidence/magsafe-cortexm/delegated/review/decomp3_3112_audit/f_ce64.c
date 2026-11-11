
undefined4 FUN_0000ce64(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  
  pcVar1 = DAT_0000ce8c;
  (*DAT_0000ce8c)(0x20,0x1000,param_3,param_4,param_4);
  (*pcVar1)(0xd8,0x10000);
  (*pcVar1)(0xd8,0x20000);
  if (param_1 != (code *)0x0) {
    (*param_1)(1);
  }
  return 0;
}

