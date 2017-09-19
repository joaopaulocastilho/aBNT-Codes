#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

#define MAX 21234
#define PAR 0
#define IMPAR 1
#define INF 1123456789
//#define DEB

typedef pair<int, int>ii;
typedef vector<ii>vii;
typedef vector<vii>vvii;

int c;
vvii LG(MAX);

int vertice(int v, int p) { return v * 2 + p; }

int dijkstra(int s, int t) {
  int dist[MAX], vis[MAX], i, v;
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < c * 2; i++) dist[i] = INF;
  dist[s] = 0;
  priority_queue < ii, vii, greater<ii> >PQ;
  PQ.push(ii(0, s));
  while (!PQ.empty()) {
    v = PQ.top().second;
    PQ.pop();
    if (vis[v]) continue;
    vis[v] = 1;
    for (i = 0; i < (int)LG[v].size(); i++) {
      if (!vis[LG[v][i].first] && dist[LG[v][i].first] > dist[v] + LG[v][i].second) {
        dist[LG[v][i].first] = dist[v] + LG[v][i].second;
        PQ.push(ii(dist[v] + LG[v][i].second, LG[v][i].first));
      }}}
  return dist[t] == INF ? -1 : dist[t];
}

int main(void) {
  int v, a, b, peso;
  scanf("%d %d", &c, &v);
  while (v--) {
    scanf("%d %d %d", &a, &b, &peso); a--; b--;
    LG[vertice(a, PAR)].push_back(ii(vertice(b, IMPAR), peso));
    LG[vertice(a, IMPAR)].push_back(ii(vertice(b, PAR), peso));
    LG[vertice(b, PAR)].push_back(ii(vertice(a, IMPAR), peso));
    LG[vertice(b, IMPAR)].push_back(ii(vertice(a, PAR), peso));
  }
  printf("%d\n", dijkstra(0, c * 2 - 2));
  #ifdef DEB
  for (int deb1 = 0; deb1 < c; deb1++) {
    for (int deb2 = 0; deb2 < (int)LG[deb1].size(); deb2++) {
      printf("Vértice: %d %s --> %d %s. Peso: %d\n", deb1 / 2 + 1, deb1 & 1 ? "Impar" : "Par",
    LG[deb1][deb2].first / 2 + 1, LG[deb1][deb2].first & 1 ? "Impar" : "Par", LG[deb1][deb2].second);
    }
  }
  #endif
  return 0;
}
