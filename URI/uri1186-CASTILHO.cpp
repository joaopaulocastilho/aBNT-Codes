#include <stdio.h>

#define MAX 12

int main(void) {
  int i, j, cont = 0, aux;
  double m[MAX][MAX], soma = 0.0;
  char c;
  scanf("%c", &c);
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) scanf("%lf", &m[i][j]);
  for (j = 1; j < MAX; j++)
    for (i = MAX - 1, aux = 0; aux < j; i--, aux++) {
      cont++;
      soma += m[i][j];
    }
  printf("%.1lf\n", (c == 'S') ? soma : soma / cont);
  return 0;
}
