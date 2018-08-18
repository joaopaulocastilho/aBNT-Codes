#include <bits/stdc++.h>

using namespace std;

#define EPS 10e-9

typedef long long ll;
typedef pair<long double, int>li;
typedef vector<li>vli;
typedef vector<vli>vvli;

typedef struct { ll x, y, z; }plan_t;

const int MAXV = 112;
const ll INF = 1123456789012;

long double dijkstra(int s, int t, vvli &LG) {
  int i, u, v;
  int vis[MAXV];
  long double dist[MAXV], peso;
  priority_queue< li, vector<li>, greater<li> >pq;
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < MAXV; i++) dist[i] = INF;
  dist[s] = 0; pq.push(li(0, s));
  while (!pq.empty()) {
    u = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i].second; peso = LG[u][i].first;
      if (dist[v] - (dist[u] + peso) > EPS) {
        dist[v] = dist[u] + peso;
        pq.push(li(dist[v], v));
      }
    }
  }
  return dist[t];
}

int main(void) {
  int caso, n, t, i, j, id, id1, id2, x, y, z, w, q, buraco[MAXV][MAXV];
  char nome[MAXV], nome2[MAXV];
  plan_t planetas[MAXV];
  ll dx, dy, dz;
  long double dist, tmp;
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    printf("Caso %d:\n", caso);
    scanf("%d", &n);
    vvli LG(n);
    map<string, int>nomes;
    for (id = i = 0; i < n; i++) {
      scanf(" %s %d %d %d", nome, &x, &y, &z);
      if (nomes.find(nome) == nomes.end()) {
        nomes[nome] = id;
        planetas[id].x = x;
        planetas[id].y = y;
        planetas[id++].z = z;
      }
    }
    scanf("%d", &w); memset(buraco, 0, sizeof(buraco));
    while (w--) {
      scanf(" %s %s", nome, nome2);
      if (nomes.find(nome) == nomes.end()) continue;
      if (nomes.find(nome2) == nomes.end()) continue;
      id1 = nomes[nome]; id2 = nomes[nome2];
      buraco[id1][id2] = 1;
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i == j) continue;
        if (buraco[i][j]) { LG[i].push_back(li(0, j)); continue; }
        dx = planetas[i].x - planetas[j].x;
        dy = planetas[i].y - planetas[j].y;
        dz = planetas[i].z - planetas[j].z;
        dist = sqrtl((long double)dx * dx + dy * dy + dz * dz);
        LG[i].push_back(li(dist, j));
      }
    }
    scanf("%d", &q);
    while (q--) {
      scanf(" %s %s", nome, nome2);
      id1 = nomes[nome]; id2 = nomes[nome2];
      tmp = dijkstra(id1, id2, LG);
      printf("A distancia de %s para %s eh %.0Lf parsecs.\n", nome, nome2, round(tmp));
    }
  }
  return 0;
}
