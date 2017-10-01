#include<stdio.h>

#define EPS 10e-9

int main(void) {
  int cont = 0;
  double nota, n[2];
  while (cont < 2) {
    scanf("%lf", &nota);
    if (nota - 10 < EPS && nota > EPS) n[cont++] = nota;
    else printf("nota invalida\n");
  }
  printf("media = %.2lf\n", (n[0] + n[1]) / 2);
  return 0;
}
