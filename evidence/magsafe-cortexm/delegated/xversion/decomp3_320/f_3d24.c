
void switchD_00003700::caseD_4(undefined4 param_1,undefined4 param_2)

{
  int unaff_r6;
  undefined4 in_cr14;
  
  coprocessor_load(0,in_cr14,param_2);
  (*(code *)**(undefined4 **)(unaff_r6 + 0x60))();
  FUN_00003140();
  return;
}

