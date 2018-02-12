#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void) {
  int n, m, problemas[MAX], qtd_resolvidos[MAX];
  int resolveu, resp, flag, i, j;
  while (scanf("%d %d", &n, &m), n) {
    resp = 0;
    memset(problemas, 0, sizeof(problemas));
    memset(qtd_resolvidos, 0, sizeof(qtd_resolvidos));
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        scanf("%d", &resolveu);
        problemas[j] += resolveu;
        qtd_resolvidos[i] += resolveu;
      }
    for (flag = 1, i = 0; flag && i < n; i++)
      flag &= (qtd_resolvidos[i] < m);
    resp += flag;
    for (flag = 1, i = 0; flag && i < m; i++)
      flag &= (problemas[i] > 0);
    resp += flag;
    for (flag = 1, i = 0; flag && i < m; i++)
      flag &= (problemas[i] < n);
    resp += flag;
    for (flag = 1, i = 0; flag && i < n; i++)
      flag &= (qtd_resolvidos[i] > 0);
    resp += flag;
    printf("%d\n", resp);
  }
  return 0;
}
