#include <stdio.h>

int main(void) {
  double a, b;
  scanf("%lf %lf", &a, &b);
  printf("%s\n", ((a + b) / 2 >= 7) ? "Aprovado" :
         ((a + b) / 2 >= 4) ? "Recuperacao" : "Reprovado");
  return 0;
}
