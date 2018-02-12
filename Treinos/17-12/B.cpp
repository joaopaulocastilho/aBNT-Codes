#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1123

int l, c, m, n, mar[MAX][MAX];

int lote(int i, int j) {
  int ia, ja, ret = 0;
  for (ia = i * m; ia < i * m + m; ia++)
    for (ja = j * n; ja < j * n + n; ja++)
      ret += mar[ia][ja];
  return ret;
}

int main(void) {
  int resp = 0, i, j;
  scanf("%d %d %d %d", &l, &c, &m, &n);
  for (i = 0; i < l; i++)
    for (j = 0; j < c; j++)
      scanf("%d", &mar[i][j]);
  for (i = 0; i < l / m; i++)
    for (j = 0; j < c / n; j++)
      resp = max(resp, lote(i, j));
  printf("%d\n", resp);
  return 0;
}
