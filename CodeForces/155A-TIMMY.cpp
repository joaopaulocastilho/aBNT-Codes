#include <cstdio>

int main(void){
  int n, first, valor, count, menor, maior;
  count = 0;
  scanf("%d", &n);
  scanf("%d", &first);
  menor = first;
  maior = first;
  while(--n){
    scanf("%d", &valor);
    if(valor > maior){ maior = valor; count++; }
    if(valor < menor){ menor = valor; count++; }
  }
  printf("%d\n", count);
  return 0;
}
