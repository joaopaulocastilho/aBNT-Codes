#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

typedef pair<int, int>ii;
typedef vector<ii>vi;

int n, memo[MAXV][3];

int maximo(int a, int b, int c) { return max(a, max(b, c)); }

int dp(int ind, int d, vi &p) {
  int i;
  if (ind >= n) return 0;
  if (memo[ind][d] != -1) return memo[ind][d];
  for (i = ind + 1; i < n; i++) {
    if (d && p[i].second - p[ind].second == 2 && p[i].first > p[ind].first)
      return memo[ind][d] = dp(i, !d, p) + 1;
    else if (!d && p[i].second - p[ind].second == -2 && p[i].first > p[ind].first)
      return memo[ind][d] = dp(i, !d, p) + 1;
  }
  return memo[ind][d] = 1;
}

int main(void) {
  int i, ans;
  while (scanf("%d", &n) != EOF) {
    vi p(n);
    for (i = 0; i < n; i++) scanf("%d %d", &p[i].first, &p[i].second);
    sort(p.begin(), p.end());
    memset(memo, -1, sizeof(memo));
    for (ans = i = 0; i < n; i++) ans = maximo(ans, dp(i, 0, p), dp(i, 1, p));
    printf("%d\n", ans);
  }
  return 0;
}
