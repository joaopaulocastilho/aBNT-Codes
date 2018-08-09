#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef vector<ii>vii;
typedef vector<vii>vvii;

const int MAXV = 312;
const int INF = 112345678;

int n, c, to_dest[MAXV];

int dijkstra(int s, int t, vvii &LG) {
  int i, u, v, w, vis[MAXV], dist[MAXV];
  for (i = 0; i < n; i++) dist[i] = INF;
  memset(vis, 0, sizeof(vis));
  priority_queue< ii, vector<ii>, greater<ii>  >pq;
  dist[s] = 0; pq.push(ii(0, s));
  while (!pq.empty()) {
    u = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i].first; w = LG[u][i].second;
      if (v < c) {
	if (dist[u] + w + to_dest[v] < dist[c - 1]) {
	  dist[c - 1] = dist[u] + w + to_dest[v];
	  pq.push(ii(dist[c - 1], c - 1));
	}
      } else if (dist[u] + w < dist[v]){
	dist[v] = dist[u] + w;
	pq.push(ii(dist[v], v));
      }
    }
  }
  return dist[t];
}

int calc(vvii &LG, int u, int t) {
  int i;
  if (u == t) to_dest[u] = 0;
  else to_dest[u] = calc(LG, u + 1, t);
  for (i = 0; i < (int)LG[u].size(); i++)
    if (LG[u][i].first == u - 1) break;
  return u ? to_dest[u] + LG[u][i].second : to_dest[u];
}

int main(void) {
  int m, k, i, u, v, p;
  while (scanf("%d %d %d %d", &n, &m, &c, &k), n) {
    vvii LG(n);
    memset(to_dest, 0, sizeof(to_dest));
    for (i = 0; i < m; i++) {
      scanf("%d %d %d", &u, &v, &p);
      LG[u].push_back(ii(v, p));
      LG[v].push_back(ii(u, p));
    }
    calc(LG, 0, c - 1);
    printf("%d\n", dijkstra(k, c - 1, LG));
  }
  return 0;
}
