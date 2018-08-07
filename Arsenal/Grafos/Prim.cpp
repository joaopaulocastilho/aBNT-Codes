/* Devolve peso da MST de um grafo em uma lista de adjacências. */

#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

#define MAX 11234
#define INF 1123456789

typedef long long ll;
typedef pair<int, int>ii;
typedef vector<ii> vii;

int n, seen[MAX], dist[MAX];

ll prim(int s, vector<vii> &LG) {
  int u, i, v, c;
  ll ret = 0;
  priority_queue< ii, vector<ii>, greater<ii> > Q;
  memset(seen, 0, sizeof(seen));
  for (u = 0; u < n; u++) dist[u] = INF;
  dist[s] = 0; Q.push(ii(0, s));
  while (!Q.empty()) {
    u = Q.top().second; Q.pop();
    if (seen[u]) continue;
    seen[u] = 1; ret += dist[u];
    for (i = 0; i < (int)LG[u].size(); i++) {
      c = LG[u][i].first; v = LG[u][i].second;
      if (dist[v] > c) {
        dist[v] = c; Q.push(ii(c, v));
      }}}
  return ret;
}

int main(void) {
  int i, k, v, c, fam = 0;
  ll resp = 0;
  scanf("%d", &n);
  vector <vii>LG(n);
  for (i = 0; i < n - 1; i++) {
    scanf("%d", &k);
    while (k--) {
      scanf("%d %d", &v, &c); v--;
      LG[i].push_back(ii(c, v)); LG[v].push_back(ii(c, i));
    }}
  for (i = 0; i < n; i++)
    if (!seen[i]) { fam++; resp += prim(i, LG); }
  printf("%d %lld\n", fam, resp);
  return 0;
}
