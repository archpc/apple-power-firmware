
int FUN_0000cd2c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  char local_18;
  undefined3 uStack_17;
  uint local_14;
  
  local_14 = param_4 & 0xffffff00;
  _local_18 = CONCAT31((int3)((uint)param_3 >> 8),100);
  uStack_20 = param_1;
  uStack_1c = param_2;
  FUN_0000131c(DAT_0000cd70,&uStack_20);
  uVar1 = DAT_0000cd74;
  *(undefined1 *)(DAT_0000cd74 + 0x10) = 1;
  *(uint **)(uVar1 + 0xc) = &local_14;
  *(undefined2 *)(uVar1 + 8) = 1;
  *(char **)(uVar1 + 4) = &local_18;
  software_interrupt(0x40);
  if ((uVar1 & 0xff) == 0) {
    FUN_00001360(DAT_0000cd70,&uStack_20);
    return (int)local_18;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000967c(3);
}

