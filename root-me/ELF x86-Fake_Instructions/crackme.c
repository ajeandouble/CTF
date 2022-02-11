#include <libc.h>

typedef  int undefined4;
typedef short undefined2;
typedef char undefined ;

void blowfish(void)
{
  uint uVar1;
  int in_GS_OFFSET;
  uint local_50;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 uStack52;
  undefined auStack50 [17];
  undefined4 local_21;
  undefined4 local_1d;
  undefined4 local_19;
  undefined4 local_15;
  undefined4 local_11;
  undefined4 local_d;
  undefined local_9;
//   undefined4 local_8;
  
//   local_8 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  local_44 = 0x6562696c;
  local_40 = 0xa9c37472;
  local_3c = 0x21;
  local_50 = 0;
  uVar1 = local_50;
  *(undefined2 *)((int)&local_38 + uVar1) = 0;
  auStack50[local_50] = 0;
  local_21 = 0x4    ;
  local_1d = 0x6d35636a;
  local_19 = 0x54352e5f;
  local_15 = 0x3887c333;
  local_11 = 0xc3304a43;
  local_d = 0x39483980;
  local_9 = 0;
  printf("good password");
  exit(0);
}


void WPA(char *param_1,char *param_2)

{
  int iVar1;
  
  param_2[11] = '\r';
  param_2[12] = '\n';
  puts("VERIF");
  iVar1 = strcmp(param_1,param_2);
  if (iVar1 == 0) {
    blowfish();
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
}


int main(int ac,char **av)

{
    blowfish();
    /*
  char **ppcVar1;
  void *dat_a;
  int i;
  char *puVar2;
  int in_GS_OFFSET;
  byte bVar3;
  char _Celebration [25];
  char local_32 [30];
  int local_14;
  
  ppcVar1 = av;
  bVar3 = 0;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (ac != 2) {
    printf("(*) -Syntaxe: %s [password] \n",*av);
                    /* WARNING: Subroutine does not return */
  /*  exit(0);
  }
  dat_a = malloc(29);
  memcpy(dat_a,&DAT_A,31);
  puVar2 = _Celebration;
  for (i = 25; i != 0; i = i + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
  }
  memcpy(_Celebration,"_Celebration",13);
  *(undefined *)((int)dat_a + 5) = 99;
  *(undefined *)((int)dat_a + 0x16) = 0;
  function_PTR = WPA;
  strcpy(local_32,ppcVar1[1]);
  *(undefined *)((int)dat_a + 8) = 0x5f;
  *(undefined *)((int)dat_a + 9) = 0x2e;
  (*function_PTR)(local_32,dat_a);

                    /* WARNING: Subroutine does not return */
  //__stack_chk_fail();*/
}

