#include <stdio.h>

#define TAM 12

int main(void) {
  int i, j, c;
  char op;
  double m[15][15], acumulado = 0.0;
  scanf("%d %c", &c, &op);
  for (i = 0; i < TAM; i++)
    for (j = 0; j < TAM; j++) {
      scanf("%lf", &m[i][j]);
      if (j == c) acumulado += m[i][j];
    }
  printf("%.1lf\n", (op == 'S') ? acumulado : acumulado / 12);
  return 0;
}
