#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

typedef pair<int, int>ii;
typedef pair<int, ii>iii;
typedef long long ll;

int main(void) {
  int n, m, flag;
  ll ans, total, i, tmp = 0;
  iii s[MAXV];
  scanf("%d %d", &n, &m);
  for (total = i = 0; i < n; i++) {
    scanf("%d %d", &s[i].second.second, &s[i].second.first);
    s[i].first = s[i].second.second - s[i].second.first;
    total += (ll)s[i].second.second;
    tmp += (ll)s[i].second.first;
  }
  if (tmp > m) { printf("-1\n"); return 0; }
  sort(s, s + n);
  //for (i = 0; i < n; i++) printf("%d %d\n", s[i].second.second, s[i].second.first);
  if (total <= m) flag = 1;
  else flag = 0;
  for (ans = 0, i = n - 1; !flag && i >= 0; i--) {
    ans++;
    total = (total - s[i].second.second) + (ll)s[i].second.first;
    if (total <= m) { flag = 1; break; }
  }
  printf("%lld\n", ans);
  return 0;
}
