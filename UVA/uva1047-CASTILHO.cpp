#include <stdio.h>

#define MAX 112345

int qtds[MAX], comp, comm[12][MAX], total[MAX];
int n, m;

int calc(int v[]) {
  int i, j, k, flag, ret = 0;
  for (i = 0; i < comp; i++)
    for (flag = 1, j = 1; flag && j <= comm[i][0]; j++) {
      for (k = 0; flag && k < m; k++) {
        if (i >= comp) break;
        if (comm[i][j] == v[k]) {
          ret += total[i];
          flag = 0;
        }
      }
    }
  for (i = 0; i < m; i++)
    ret += qtds[v[i]];
  return ret;
}

int main(void) {
  int i, j, v[MAX], lim[MAX], vresp[MAX], resp, tmp, caso = 1;
  while (scanf("%d %d", &n, &m), n) {
    resp = 0;
    printf("Case Number  %d\n", caso); caso++;
    for (i = 1; i <= n; i++) scanf("%d", &qtds[i]);
    scanf("%d", &comp);
    for (i = 0; i < comp; i++) {
      scanf("%d", &comm[i][0]);
      for (j = 1; j <= comm[i][0]; j++)
        scanf("%d", &comm[i][j]);
      scanf("%d", &total[i]);
      for (j = 1; j <= comm[i][0]; j++)
        qtds[comm[i][j]] -= total[i];
    }
    for (i = 0; i < m; i++) v[i] = i + 1;
    for (i = m - 1, j = 0; i >= 0; i--, j++) lim[i] = n - j;
    for (i = m - 1; ; ) {
      if (v[i] < lim[i]) {
        tmp = calc(v);
        if (resp < tmp) {
          resp = tmp;
          for (i = 0; i < m; i++) vresp[i] = v[i];
        }
        v[i]++;
        for (j = i + 1; j < m; j++) v[j] = v[j - 1] + 1;
        i = m - 1;
        continue;
      }
      i--;
      if (i < 0) break;
    }
    tmp = calc(v);
    if (resp < tmp) {
      resp = tmp;
      for (i = 0; i < m; i++) vresp[i] = v[i];
    }
    printf("Number of Customers: %d\n", resp);
    printf("Locations recommended:");
    for (i = 0; i < m; i++) printf(" %d", vresp[i]);
    printf("\n\n");
  }
  return 0;
}
