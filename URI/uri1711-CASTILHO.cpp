#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 11234
#define INF 112345678

typedef pair<int, int>ii;
typedef vector<ii>vii;
typedef vector<vii>vvii;

int seen[MAX], low[MAX], d[MAX], tempo, va[MAX], acesso[MAX][112], s;

void tarjan(vvii &LG, vvii &_LG, int u, int pai) {
  int i, v, peso;
  seen[u] = 1;
  d[u] = low[u] = tempo++;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i].first; peso = LG[u][i].second;
    if (!seen[v]) {
      tarjan(LG, _LG, v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] <= d[u]) {
        acesso[u][v] = acesso[v][u] = 1;
        _LG[u].push_back(ii(v, peso));
        _LG[v].push_back(ii(u, peso));
      }
    } else if (v != pai) {
      low[u] = min(low[u], d[v]);
      if (!acesso[u][v]) {
        acesso[u][v] = acesso[v][u] = 1;
        _LG[u].push_back(ii(v, peso));
        _LG[v].push_back(ii(u, peso));
      }}}}

int dfs(vvii &LG, int u, int soma, int origem, int pai) {
  int i, v, peso;
  seen[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i].first; peso = LG[u][i].second;
    if (!seen[v]) return va[u] = dfs(LG, v, soma + peso, origem, u);
    if (v != pai) return va[u] = soma + peso;
  }
  return 0;
}

int dijkstra(vvii &LG, int u, int comp) {
  int dist[MAX], vis[MAX], i, resp = INF, v;
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < s; i++) dist[i] = INF;
  dist[u] = 0;
  priority_queue< ii, vii, greater<ii> >pq;
  pq.push(ii(dist[u], u));
  while (!pq.empty()) {
    v = pq.top().second;
    pq.pop();
    if (vis[v]) continue;
    vis[v] = 1;
    if (va[v] >= comp) resp = min(resp, (2 * dist[v]) + va[v]);
    for (i = 0; i < (int)LG[v].size(); i++) {
      int w = LG[v][i].first;
      int peso = LG[v][i].second;
      if (!vis[w] && dist[w] > dist[v] + peso) {
        dist[w] = dist[v] + peso;
        pq.push(ii(dist[w], w));
      }
	  //if (va[w] >= comp) resp = min(resp, (2 * dist[w]) + va[w]);
    }
  }
  return (resp == INF) ? -1 : resp;
}

int main(void) {
  int i, t, a, b, c, x, comp, q;
  while (scanf("%d %d", &s, &t) != EOF) {
    vvii LG(s + 1);
    vvii _LG(s + 1);
    for (i = 0; i < t; i++) {
      scanf("%d %d %d", &a, &b, &c); a--; b--;
      LG[a].push_back(ii(b, c));
      LG[b].push_back(ii(a, c));
    }
    memset(seen, 0, sizeof(seen)); tempo = 0;
    memset(acesso, 0, sizeof(acesso));
    for (i = 0; i < s; i++) if (!seen[i]) tarjan(LG, _LG, i, i);
    memset(seen, 0, sizeof(seen));
    memset(va, 0, sizeof(va));
    for (i = 0; i < s; i++) if (!seen[i]) dfs(_LG, i, 0, i, i);
    //for (i = 0; i < s; i++) printf("%d ", va[i]);
    //printf("\n");
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
      scanf("%d %d", &x, &comp); x--;
      printf("%d\n", dijkstra(LG, x, comp));
    }
  }
  return 0;
}
