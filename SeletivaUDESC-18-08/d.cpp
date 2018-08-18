#include <bits/stdc++.h>

using namespace std;

#define EPS 10e-9

typedef pair<double, double>ii;
typedef vector<ii>vii;

const int MAXV = 212;
const int INF = 112345678;

int n, memo[MAXV][MAXV];

int dp(int i, int j, vii &v) {
  int ans = 0;
  if (i > n || j > n) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  if (v[i].first < v[j].first && v[i].second > v[j].second) {
    // printf("aoeu\n");
    ans = dp(j, j + 1, v) + 1;
  }
  return memo[i][j] = max(ans, dp(i, j + 1, v));
}

int main(void) {
  int i, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vii v(n + 1);
    for (i = 1; i <= n; i++) scanf("%lf %lf", &v[i].first, &v[i].second);
    v[0].first = - 2; v[0].second = INF;
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(0, 1, v));
  }
  return 0;
}
