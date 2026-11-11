
undefined8 FUN_000013ac(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = param_2 & 0xffffff00;
  local_10 = *(undefined4 *)(DAT_000013d4 + 0x48);
  local_c = param_4;
  FUN_000011a0(param_1,0,DAT_000013d8,&local_14);
  while ((char)local_14 == '\0') {
    software_interrupt(1);
  }
  return CONCAT44(local_14,param_1);
}

