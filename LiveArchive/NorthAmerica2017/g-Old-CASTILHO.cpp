#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;
const int RES = 21234;

int n, m, v[MAXV], memo[MAXV][RES][2];

int dp(int i, int c, int e, int ant) {
  int novo_c, tmp;
  if (i >= n) return 0;
  if (memo[i][c][e] != -1) return memo[i][c][e];
  novo_c = (2 * c) / 3;
  tmp = dp(i + 1, novo_c, 0, c) + min(c, v[i]);
  if (e == 0) return memo[i][c][e] = max(dp(i + 1, ant, 1, c), tmp);
  return memo[i][c][e] = max(dp(i + 1, m, 0, m), tmp);
}

int main(void) {
  int i;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(0, m, 0, m));
  }
  return 0;
}
