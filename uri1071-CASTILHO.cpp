#include<stdio.h>

int main(void) {
  int inf, sup, aux, i, soma = 0;
  scanf("%d %d", &inf, &sup);
  if (inf > sup) {
    aux = inf;
    inf = sup;
    sup = aux;
  }
  for (i = inf + 1; i < sup; i++) soma += (i & 1) ? i : 0;
  printf("%d\n", soma);
  return 0;
}
