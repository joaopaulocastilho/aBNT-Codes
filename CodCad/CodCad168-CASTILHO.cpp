#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef vector<ii>vii;

const int MAXV = 1123;
const int INF = 112345678;

int memo[MAXV][MAXV], ans;
vii v;

int dp(int c, int t) {
  int ans, maior_resistencia;
  if (t == 0) return INF;
  if (t > c + 1) return -INF;
  if (c == 0) return v[c].first - v[c].second;
  if (memo[c][t] != -1) return memo[c][t];
  ans = dp(c - 1, t);
  maior_resistencia = dp(c - 1, t - 1);
  if (maior_resistencia >= v[c].second)
    ans = max(ans, min(maior_resistencia - v[c].second, v[c].first - v[c].second));
  return memo[c][t] = ans;
}

void bbin(int l, int r, int n) {
  if (l > r) return;
  int m = (l + r) / 2;
  if (dp(n - 1, m) >= 0) { ans = m; bbin(m + 1, r, n); }
  else bbin(l, m - 1, n);
}

int main(void) {
  int n, i, peso, resis;
  memset(memo, -1, sizeof(memo));
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &peso, &resis);
    v.push_back(ii(resis, peso));
  }
  sort(v.begin(), v.end(), greater<ii>());
  ans = 1; bbin(1, n - 1, n);
  printf("%d\n", ans);
  return 0;
}
