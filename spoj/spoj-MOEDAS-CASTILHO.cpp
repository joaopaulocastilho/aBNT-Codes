#include <bits/stdc++.h>

using namespace std;

const int MAXV = 51234;
const int INF = 112345678;

int main(void) {
  int m, i, j, k, n, cont, moedas[MAXV], memo[MAXV];
  while (scanf("%d", &m), m) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &moedas[i]);
    for (i = 0; i <= m; i++) memo[i] = INF;
    for (i = 0; i < n; i++) {
      for (cont = 1, j = moedas[i]; j <= m; j += moedas[i], cont++)
	memo[j] = min(memo[j], cont);
    }
    for (i = 1; i <= m; i++) {
      if (memo[i] == INF) continue;
      for (j = 0; j < n; j++) {
    	for (k = moedas[j] + i, cont = memo[i] + 1; k <= m; k += moedas[j], cont++)
	  memo[k] = min(memo[k], cont);
      }
    }
    if (memo[m] == INF) printf("Impossivel\n");
    else printf("%d\n", memo[m]);
  }
  return 0;
}
