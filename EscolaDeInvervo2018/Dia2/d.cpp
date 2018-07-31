#include <bits/stdc++.h>

using namespace std;

const int MAXV = 212;
const int INF = 112345678;

typedef pair<int, int>ii;
typedef vector<ii>vii;
typedef vector<vii>vvii;

int n;

int prim(int s, vvii &LG) {
  int u, i, v, w, dist[MAXV], vis[MAXV], ret = 0;
  priority_queue< ii, vector<ii>, greater<ii> >pq;
  for (i = 0; i <= n; i++) dist[i] = INF;
  memset(vis, 0, sizeof(vis));
  dist[s] = 0; pq.push(ii(0, s));
  while (!pq.empty()) {
    u = pq.top().second; pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    ret += dist[u];
    for (i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i].first; w = LG[u][i].second;
      if (dist[v] > w) {
        dist[v] = w;
        pq.push(ii(dist[v], v));
      }
    }
  }
  return ret;
}

int main(void) {
  int t, caso, i, m, k, u, v, w;
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    printf("Case #%d: ", caso);
    scanf("%d %d %d", &n, &m, &k);
    vvii LG(n + 1);
    for (i = 0; i < k; i++) {
      scanf("%d", &u); u--;
      LG[n].push_back(ii(u, 0));
      LG[u].push_back(ii(n, 0));
    }
    for (i = 0; i < m; i++) {
      scanf("%d %d %d", &u, &v, &w); u--; v--;
      LG[u].push_back(ii(v, w));
      LG[v].push_back(ii(u, w));
    }
    printf("%d\n", prim(0, LG));
  }
  return 0;
}
