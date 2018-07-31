#include <bits/stdc++.h>

using namespace std;

const int MAXV = 4123;
const int MAXC = 61;
const int INF = 112345678;

typedef pair<int, int>ii;
typedef pair<ii, int>iii;
typedef vector<iii>viii;
typedef vector<viii>vviii;

int dijkstra(int s, int t, vviii &LG) {
  int i, j, u, v, w, f, current, ret, vis[MAXV][31], dist[MAXV][31];
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < MAXV; i++)
    for (j = 0; j < 30; j++)
      dist[i][j] = INF;
  priority_queue< iii, vector<iii>, greater<iii> >pq;
  pq.push(iii(ii(0, s), 30)); dist[s][30] = 0;
  while (!pq.empty()) {
    u = pq.top().first.second; f = pq.top().second;
    pq.pop();
    if (vis[u][f]) continue;
    vis[u][f] = 1;
    for (i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i].first.first; w = LG[u][i].first.second;
      current = LG[u][i].second;
      if (current != f && dist[u][f] + w < dist[v][current]) {
        dist[v][current] = dist[u][f] + w;
        pq.push(iii(ii(dist[v][current], v), current));
      }
    }
  }
  for (ret = INF, i = 0; i < 30; i++)
    ret = min(ret, dist[t][i]);
  return (ret == INF) ? -1 : ret;
}

int main(void) {
  int m, ind, u, v, w, f, i, ans;
  char o[MAXC], d[MAXC], idi1[MAXC], idi2[MAXC], p[MAXC];
  while (scanf("%d", &m), m) {
    map<string, int>idiomas;
    vviii LG(MAXV);
    scanf(" %s %s", o, d);
    idiomas[o] = 0;
    idiomas[d] = 1;
    ind = 2;
    for (i = 0; i < m; i++) {
      scanf(" %s %s %s", idi1, idi2, p);
      if (idiomas.find(idi1) == idiomas.end()) idiomas[idi1] = ind++;
      if (idiomas.find(idi2) == idiomas.end()) idiomas[idi2] = ind++;
      u = idiomas[idi1]; v = idiomas[idi2]; w = strlen(p); f = p[0] - 'a';
      LG[u].push_back(iii(ii(v, w), f));
      LG[v].push_back(iii(ii(u, w), f));
    }
    ans = dijkstra(0, 1, LG);
    if (ans == -1) printf("impossivel\n");
    else printf("%d\n", ans);
  }
  return 0;
}
