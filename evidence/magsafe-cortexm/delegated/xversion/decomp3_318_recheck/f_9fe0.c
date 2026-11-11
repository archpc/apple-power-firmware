
void FUN_00009fe0(uint param_1,uint param_2)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  
  FUN_00009f90();
  puVar2 = DAT_0000a014;
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *DAT_0000a014 = param_1;
  *puVar2 = param_2 >> 0x10 & 0xff;
  *puVar2 = param_2 >> 8 & 0xff;
  *puVar2 = param_2 & 0xff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  FUN_00009eb4(uVar3);
  FUN_00009f48();
  return;
}

