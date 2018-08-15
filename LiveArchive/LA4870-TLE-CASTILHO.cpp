#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef vector<ii>vii;

const int MAXV = 1123;
const int MAXF = 21234;
const int INF = 112345678;

int memo[MAXV][MAXF], k, l;
vii v;

int dp(int c, int f) {
  int ans, me;
  if (f == 0) return 0;
  if (c == 0) {
    if (f == v[c].second) return v[c].first;
    return INF;
  }
  if (memo[c][f] != -1) return memo[c][f];
  ans = dp(c - 1, f);
  if (ans > l) ans = INF;
  ans = max(ans - k, 0);
  me = dp(c - 1, f - v[c].second);
  if (me + v[c].first <= l)
    ans = min(ans, me + v[c].first);
  return memo[c][f] = ans;
}

int main(void) {
  int n, i, f, d, ans;
  while (scanf("%d %d %d", &n, &k, &l), n) {
    v.clear();
    for (i = 0; i < n; i++) {
      scanf("%d %d", &f, &d);
      v.push_back(ii(d, f));
    }
    sort(v.begin(), v.end());
    memset(memo, -1, sizeof(memo));
    for (ans = 0, i = MAXF - 1; i; i--) {
      if (dp(n - 1, i) <= l) { ans = i; break; }
    }
    printf("%d\n", ans);
  }
  return 0;
}
