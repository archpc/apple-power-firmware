
void switchD_0000e27a::caseD_14(undefined4 param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  int iStack00000018;
  int in_stack_0000001c;
  uint uStack00000024;
  
  iStack00000018 = DAT_0000ec1c + 0xf1;
  uStack00000024 = param_2;
  while( true ) {
    if (param_2 == 2) break;
    for (uVar4 = 0; uVar4 != 2; uVar4 = uVar4 + 1) {
      iVar2 = FUN_00007e4c(uVar4 & 0xff,param_2 & 0xff,3);
      uVar3 = FUN_00007e4c(uVar4 & 0xff,param_2 & 0xff,2);
      iVar2 = FUN_00000880(iVar2 << 0x10,uVar3);
      uStack00000024 = in_stack_0000001c + uStack00000024 + (iStack00000018 * iVar2 >> 0x10) + 10;
    }
    param_2 = param_2 + 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((in_stack_00000004 & 1) == 1);
  }
  uVar3 = FUN_0000077a(in_stack_0000000c,0x18,DAT_0000ec20,in_stack_00000008);
  FUN_0000e238(in_stack_00000010,in_stack_00000014,in_stack_0000000c,uVar3);
  return;
}

