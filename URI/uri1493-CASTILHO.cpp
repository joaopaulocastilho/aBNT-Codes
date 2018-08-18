#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

typedef vector<int>vi;
typedef vector<vi>vvi;

int c, memo[MAXV][MAXV];
vi LG[MAXV];

int dp(int i, int j) {
  int it, ret = 0;
  if (i == j && i == 0) return 1;
  if (i == j) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  if (i > j) swap(i, j);
  for (it = 0; it < (int)LG[j].size(); it++) ret |= dp(i, LG[j][it]);
  return memo[i][j] = memo[j][i] = ret;
}

int main(void) {
  int i, j, p, ans, u, v;
  while (scanf("%d %d", &c, &p) != EOF) {
    for (i = 0; i < c; i++) LG[i].clear();
    for (i = 0; i < p; i++) {
      scanf("%d %d", &u, &v); u--; v--;
      LG[v].push_back(u);
    }
    memset(memo, -1, sizeof(memo));
    for (ans = i = 0; i < c; i++)
      for (j = i + 1; j < c; j++) ans += dp(i, j);
    printf("%d\n", ans);
  }
  return 0;
}
