
void switchD_00003700::caseD_3(void)

{
  int unaff_r5;
  
  if (*(char *)(unaff_r5 + 0xe2) != '\0') {
    *(undefined1 *)(unaff_r5 + 0xe2) = 0;
    FUN_00003258();
  }
  FUN_00003258();
  return;
}

