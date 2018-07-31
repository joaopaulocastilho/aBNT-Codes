#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;

int main(void) {
  int casos, t, n, m, i, d, pos, ind, ind2, resp;
  scanf("%d", &t);
  for (casos = 1; casos <= t; casos++) {
    printf("Case #%d: ", casos);
    scanf("%d %d", &n, &m);
    vector<int>v(n);
    vector<ii>dist;
    vector<ii>divisao;
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    if (m == 1) { printf("%d\n", v[n - 1] - v[0]); continue; }
    for (i = 1; i < n; i++) {
      d = v[i] - v[i - 1];
      pos = i - 1;
      dist.push_back(ii(d, pos));
    }
    sort(dist.begin(), dist.end());
    for (ind = n - 2, i = 0; i < m - 1; i++, ind--)
      divisao.push_back(ii(dist[ind].second, dist[ind].first));
    sort(divisao.begin(), divisao.end());
    ind = divisao[0].first;
    resp = v[ind] - v[0];
    for (i = 1; i < m - 1; i++) {
      ind = divisao[i].first;
      ind2 = divisao[i - 1].first + 1;
      resp += v[ind] - v[ind2];
    }
    resp += v[n - 1] - v[divisao[m - 2].first + 1];
    printf("%d\n", resp);
  }
  return 0;
}
