
void FUN_0000072c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int local_28;
  uint local_24;
  undefined4 local_20;
  
  local_20 = DAT_00000770;
  param_2 = param_2 & 0x7fffffff;
  uVar2 = param_2 - 1;
  local_24 = 0;
  if (uVar2 < param_2) {
    local_24 = uVar2;
  }
  local_28 = param_1;
  uVar1 = FUN_000001d0(&local_28,param_3,param_4);
  if ((param_1 != 0) && (param_2 != 0)) {
    if (local_24 != 0) {
      uVar2 = uVar1;
    }
    *(undefined1 *)(param_1 + uVar2) = 0;
  }
  return;
}

