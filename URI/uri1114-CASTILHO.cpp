#include<stdio.h>

int main(void) {
  int pss;
  while(scanf("%d", &pss), pss != 2002) printf("Senha Invalida\n");
  printf("Acesso Permitido\n");
  return 0;
}
