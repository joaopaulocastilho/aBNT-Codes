#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 212345
#define INF 1123456789

typedef pair<int, int>ii;
typedef vector<ii>vii;

int n;

int prim(int s, vector<vii> &LG) {
  int vis[MAX], dist[MAX];
  int u, v, i, ret = 0, peso;
  priority_queue< ii, vector<ii>, greater<ii> > PQ;
  memset(vis, 0, sizeof(vis));
  for (u = 0; u < n; u++) dist[u] = INF;
  dist[s] = 0; PQ.push(ii(0, s));
  while (!PQ.empty()) {
    u = PQ.top().second; PQ.pop();
    if (vis[u]) continue;
    vis[u] = 1; ret += dist[u];
    for (i = 0; i < (int)LG[u].size(); i++) {
      peso = LG[u][i].first; v = LG[u][i].second;
      if (dist[v] > peso) {
        dist[v] = peso; PQ.push(ii(peso, v));
      }}}
  return ret;
}

int main(void) {
  int m, u, v, w, soma, menor;
  while (scanf("%d %d", &n, &m), n) {
    vector<vii> LG(n); soma = 0;
    while (m--) {
      scanf("%d %d %d", &u, &v, &w); soma += w;
      LG[u].push_back(ii(w, v));
      LG[v].push_back(ii(w, u));
    }
    menor = (n > 1) ? prim(0, LG) : 0;
    printf("%d\n", soma - menor);
  }
  return 0;
}
