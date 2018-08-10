#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

typedef pair<int, int>ii;

int main(void) {
  int t, caso, n, ans, current, i, ind, k, v[MAXV];
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    vector<ii>dist;
    vector<int>cortes;
    printf("Case #%d: ", caso);
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v, v + n);
    if (k == 1) { printf("%d\n", v[n - 1] - v[0]); continue; }
    if (k == n) { printf("0\n"); continue; }
    for (i = 1; i < n; i++) dist.push_back(ii(v[i] - v[i - 1], i));
    sort(dist.begin(), dist.end());
    for (i = 0, ind = (int)dist.size() - 1; i < k - 1; i++, ind--)
      cortes.push_back(dist[ind].second);
    sort(cortes.begin(), cortes.end());
    current = cortes[0];
    ans = v[current - 1] - v[0];
    for (i = 1; i < k - 1; i++) {
    current = cortes[i];
     ans += v[current - 1] - v[cortes[i - 1]];
    }
    ans += v[n - 1] - v[cortes[k - 2]];
    printf("%d\n", ans);
  }
  return 0;
}
