#include <stdio.h>
#include <stdlib.h>

#define MAX 1123
#define INF 112345678

int main(void) {
  int n, i, m, casos, j, q, v[MAX], menor, resp;
  for (casos = 1; scanf("%d", &n), n; casos++) {
    printf("Case %d:\n", casos);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    scanf("%d", &m);
    while (m--) {
      scanf("%d", &q);
      for (menor = INF, i = 0; i < n; i++)
        for (j = 1; j < n; j++)
          if (v[i] != v[j] && abs((v[i] + v[j]) - q) < menor)
            { resp = v[i] + v[j]; menor = abs((v[i] + v[j]) - q); }
      printf("Closest sum to %d is %d.\n", q, resp);
    }
  }
  return 0;
}
