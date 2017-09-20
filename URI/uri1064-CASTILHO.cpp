#include<stdio.h>

int main(void) {
  int i, pos = 0;
  double n, soma = 0.;
  for (i = 0; i < 6; i++) {
    scanf("%lf", &n);
    if (n > 0) { pos++; soma += n; }
  }
  printf("%d valores positivos\n%.1lf\n", pos, soma/pos);
  return 0;
}
