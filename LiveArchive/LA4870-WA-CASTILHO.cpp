#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef vector<ii>vii;

const int MAXV = 1123;
const int MAXF = 21234;
const int INF = 112345678;

ii memo[MAXV][MAXV];
int k, l, n;
vii v;

ii dp(int c, int t) {
  ii ans, me;
  if (t == 0) return ii(-INF, 0);
  if (c == 0) {
    if (t == 1 && v[c].first <= l) return ii(v[c].second, v[c].first);
    return ii(-INF, INF);
  }
  if (memo[c][t].first != -1) return memo[c][t];
  ans = dp(c - 1, t);
  if (ans.second > l) ans.second = INF;
  ans.second = max(ans.second - k, 0);
  me = dp(c - 1, t - 1);
  if (me.second + v[c].first <= l) {
    if (ans.first < me.first + v[c].second) {
      ans.first = me.first + v[c].second;
      ans.second = me.second + v[c].first;
    }
  }
  return memo[c][t] = ans;
}

int main(void) {
  int i, f, d, ans;
  ii tmp;
  while (scanf("%d %d %d", &n, &k, &l), n) {
    v.clear();
    for (i = 0; i < n; i++) {
      scanf("%d %d", &f, &d);
      v.push_back(ii(d, f));
    }
    //sort(v.begin(), v.end());
    memset(memo, -1, sizeof(memo));
    for (ans = 0, i = n; i; i--) {
      tmp = dp(n - 1, i);
      ans = max(ans, tmp.first);
    }
    printf("%d\n", ans);
  }
  return 0;
}
