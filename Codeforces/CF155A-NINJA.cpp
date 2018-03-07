#include <stdio.h>

int main(void){
  int i, n, pior, melhor, atual, resp = 0;

  scanf("%d", &n);
  scanf("%d", &pior);
  for(melhor = pior, i = 1; i < n; i++){
    scanf("%d", &atual);
    if(atual < pior) { pior = atual; resp++; }
    else if(atual > melhor) { melhor = atual; resp++; }
  }
  printf("%d\n", resp);
  
  return 0;
}
