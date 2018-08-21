#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;
const int MAXM = 27;
const int INF = 112345678;

int l, h, v[MAXV], marca[MAXV], memo[MAXV][MAXM], calc[MAXV][MAXM];

int dp(int i, int q) {
  if (q + marca[i] > h) return -INF;
  if (i == 0 && (q + marca[i] < l || q + marca[i] > h)) return -INF;
  if (i == 0) return v[0];
  if (calc[i][q]) return memo[i][q];
  calc[i][q] = 1;
  if (q + marca[i] >= l)
    return memo[i][q] = max(v[i], v[i] + dp(i - 1, q + marca[i]));
  return memo[i][q] = dp(i - 1, q + marca[i]) + v[i];
}

int main(void) {
  int n, i, ans;
  scanf("%d %d %d", &n, &l, &h);
  memset(marca, 0, sizeof(marca));
  memset(calc, 0, sizeof(calc));
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  for (i = 0; i < n; i++) scanf("%d", &marca[i]);
  for (ans = -INF, i = 0; i < n; i++)
    ans = max(ans, dp(i, 0));
  printf("%d\n", ans);
  return 0;
}
