#include <stdio.h>

int fat(int n){
  if(!n || n==1) return 1;
  return n*fat(n-1);
}

int main(void){
  int N, cmp=0, i=9, cont=0, aux;
  scanf("%d", &N);
  while(cmp!=N && i){
    aux = fat(i);
    while(aux+cmp <= N){
      cmp+=aux;
      cont++;
    }
    i--;
  }
  printf("%d\n", cont);
  return 0;
}
