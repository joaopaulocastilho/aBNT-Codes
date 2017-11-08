#include <stdio.h>

int main(void){
  int maior = -1, atual;

  while(scanf("%d", &atual), atual)
    if(atual > maior) maior = atual;
  printf("%d\n", maior);

  return 0;
}
