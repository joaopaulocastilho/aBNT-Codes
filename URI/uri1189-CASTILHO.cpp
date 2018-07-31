#include <stdio.h>

#define MAX 12
#define INFL 1
#define SUPL 10

int main(void) {
  int i, j, inf, sup, linha, i_aux, j_aux, qtd = 0;
  double m[MAX][MAX], m_aux[MAX][MAX], soma = 0.0;
  char op;
  scanf("%c", &op);
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) scanf("%lf", &m_aux[i][j]);
  for (j_aux = 0, i = 0; i < MAX; i++, j_aux++)
    for (i_aux = MAX - 1, j = 0; j < MAX; i_aux--, j++)
      m[i][j] = m_aux[i_aux][j_aux];
  // for (i = 0; i < MAX; i++) {
  //  printf("\n");
  //  for (j = 0; j < MAX; j++) printf("%lf ", m[i][j]);
  // }
  for (inf = INFL, sup = SUPL, linha = 0;
       sup - inf >= 1; inf++, sup--, linha++) {
    for (i = inf, j = linha; i <= sup; i++) { soma += m[j][i]; qtd++; }
  }
  printf("%.1lf\n", (op == 'S') ? soma : soma / qtd);
  return 0;
}
