#include <bits/stdc++.h>

using namespace std;

const int MAXV = 11234;

int n, v[MAXV], memo[MAXV][2];

int dp(int i, int estado) {
  int r1, r2;
  if (i == n) return 0;
  if (memo[i][estado] != -1) return memo[i][estado];
  r1 = dp(i + 1, 1) + v[i];
  r2 = estado ? 0 : dp(i + 1, 0);
  return memo[i][estado] = max(r1, r2);
}

int main(void) {
  int i, ans;
  while (scanf("%d", &n), n) {
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    memset(memo, -1, sizeof(memo));
    ans = dp(0, 0);
    if (ans > 0)
      printf("The maximum winning streak is %d.\n", ans);
    else printf("Losing streak.\n");
  }
  return 0;
}
