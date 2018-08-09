#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int m[MAXV][MAXV], ac[MAXV][MAXV], memo[MAXV][MAXV][MAXV];

int dp(int h, int l, int r) {
  if (h < 0) return 0;
  if (h == 0) return max(ac[h][l], ac[h][r]);
  if (memo[h][l][r] != -1) return memo[h][l][r];
  return memo[h][l][r] = max(dp(h - 1, l + 1, r) + ac[h][l],
	     dp(h - 1, l, r - 1) + ac[h][r]);
}

int main(void) {
  int  i, j, ans, n;
  scanf("%d", &n);
  memset(ac, 0, sizeof(ac));
  memset(memo, -1, sizeof(memo));
  for (ans = 0, i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
      if (i == 0) ac[i][j] = m[i][j];
      else ac[i][j] += ac[i - 1][j] + m[i][j];
      ans += m[i][j];
    }
  printf("%d\n", ans - dp(n - 2, 0, n - 1));
  return 0;
}
