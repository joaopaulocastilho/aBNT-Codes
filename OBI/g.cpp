#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef vector<ii>vii;

const int MAXV = 1123;

int n, r, memo[MAXV][MAXV];
vii v;

int dp(int i, int j) {
  if (i == (int)v.size()) return 0;
  if (j > r) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  if (j + v[i].second > r) return memo[i][j] = dp(i + 1, j);
  return memo[i][j] = max(dp(i + 1, j), dp(i + 1, j + v[i].second) + v[i].first);
}

int main(void) {
  int i, qtd, p, ans;
  char tipo;
  vii g, b, c;
  scanf("%d %d", &n ,&r);
  for (i = 0; i < n; i++) {
    scanf("%d %c %d", &qtd, &tipo, &p);
    if (tipo == 'G') g.push_back(ii(qtd, p));
    else if (tipo == 'B') b.push_back(ii(qtd, p));
    else c.push_back(ii(qtd, p));
  }
  for (i = 0; i < (int)g.size(); i++) v.push_back(g[i]);
  for (i = 0; i < (int)b.size(); i++) v.push_back(b[i]);
  memset(memo, -1, sizeof(memo));
  ans = dp(0, 0);
  v.clear();
  for (i = 0; i < (int)g.size(); i++) v.push_back(g[i]);
  for (i = 0; i < (int)c.size(); i++) v.push_back(c[i]);
  memset(memo, -1, sizeof(memo));
  ans = max(ans, dp(0, 0));
  v.clear();
  for (i = 0; i < (int)b.size(); i++) v.push_back(b[i]);
  for (i = 0; i < (int)c.size(); i++) v.push_back(c[i]);
  memset(memo, -1, sizeof(memo));
  ans = max(ans, dp(0, 0));
  printf("%d\n", ans);
  return 0;
}
