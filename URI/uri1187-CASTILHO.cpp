#include <stdio.h>

#define MAX 12
#define INFL 1
#define SUPL 10

int main(void) {
  int i, j, inf, sup, linha, qtd = 0;
  double m[MAX][MAX], soma = 0.0;
  char op;
  scanf("%c", &op);
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) scanf("%lf", &m[i][j]);
  for (inf = INFL, sup = SUPL, linha = 0;
       sup - inf >= 1; inf++, sup--, linha++) {
    for (i = inf, j = linha; i <= sup; i++) { soma += m[j][i]; qtd++; }
  }
  printf("%.1lf\n", (op == 'S') ? soma : soma / qtd);
  return 0;
}
