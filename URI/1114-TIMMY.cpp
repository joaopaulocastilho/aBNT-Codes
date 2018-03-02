#include <cstdio>
#include <cstring>

#define MAX 112345

int main(void){
  char string[MAX];
  while(scanf("%s", string), strcmp(string, "2002") != 0)
    printf("Senha Invalida\n");
  printf("Acesso Permitido\n");

  return 0;
}
