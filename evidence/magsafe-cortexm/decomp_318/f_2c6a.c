
/* WARNING: Control flow encountered bad instruction data */

void FUN_00002c6a(void)

{
  undefined8 in_d19;
  undefined8 in_d28;
  
  VectorRoundShiftRightAccumulate(in_d28,in_d19,1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

