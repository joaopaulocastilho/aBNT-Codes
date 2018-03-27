#include <stdio.h>

#define EPS 10e-9
#define nvalido(x) ((x) < EPS || (x) - 10.0 > EPS)

int main(void) {
  int roda = 1;
  double n[3], nota;
  while (roda == 1) {
    while (scanf("%lf", &nota), nvalido(nota))
      printf("nota invalida\n");
    n[0] = nota;
    while (scanf("%lf", &nota), nvalido(nota))
      printf("nota invalida\n");
    n[1] = nota;
    printf("media = %.2lf\n", (n[0] + n[1]) / 2.);
    for (roda = 3; !(roda == 1 || roda == 2); ) {
      printf("novo calculo (1-sim 2-nao)\n");
      scanf("%d", &roda);
    }}
  return 0;
}
