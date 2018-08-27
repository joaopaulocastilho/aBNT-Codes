#include <bits/stdc++.h>

using namespace std;

const int MAXM = 112;
const int MAXV = 21234;

int n, m, meal[MAXM], memo[MAXM][MAXV];

int dp(int i, int r) {
  int nr, r1, r2, r3, qtd, &est = memo[i][r];
  if (i >= n) return 0;
  if (est != -1) return est;
  qtd = min(meal[i], r);
  nr = (r * 2) / 3;
  r1 = dp(i + 1, nr) + qtd;
  r2 = dp(i + 2, r) + qtd;
  r3 = dp(i + 3, m) + qtd;
  est = max(r1, max(r2, r3));
  return est;
}

int main(void) {
  int i, ans;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &meal[i]);
    memset(memo, -1, sizeof(memo));
    for (ans = i = 0; i < n; i++) ans = max(ans, dp(i, m));
    printf("%d\n", ans);
  }
  return 0;
}
