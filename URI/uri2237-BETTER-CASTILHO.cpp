#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;
typedef pair<int, int>ii;
typedef pair<int, vi>iv;
typedef pair<int, iv>iiv;

const int MAXV = 9;
const int MAXN = 41234;
const int INF = 112345678;

int n;
map<vi, int>vert;
vi s1(MAXV);
vi t1(MAXV);

int troca[][2] =
  { { 0, 1 },
    { 1, 2 },
    { 2, 3 },
    { 4, 5 },
    { 5, 6 },
    { 6, 7 },
    { 0, 4 },
    { 1, 5 },
    { 2, 6 },
    { 3, 7 }};

int dijkstra(int s, int t) {
  int dist[MAXN], vis[MAXN], i, u, v, w;
  for (i = 0; i < MAXN; i++) dist[i] = INF;
  memset(vis, 0, sizeof(vis));
  priority_queue< iiv, vector<iiv>, greater<iiv> >pq;
  dist[s] = 0; pq.push(iiv(0, iv(s, s1)));
  while (!pq.empty()) {
    vi v_vert = pq.top().second.second;
    u = pq.top().second.first;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (i = 0; i < 10; i++) {
      w = v_vert[troca[i][0]] + v_vert[troca[i][1]];
      swap(v_vert[troca[i][0]], v_vert[troca[i][1]]);
      if (vert.find(v_vert) == vert.end()) vert[v_vert] = n++;
      v = vert[v_vert];
      if (dist[u] + w < dist[v]) {
	dist[v] = dist[u] + w;
	pq.push(iiv(dist[v], iv(v, v_vert)));
      }
      swap(v_vert[troca[i][0]], v_vert[troca[i][1]]);
    }
  }
  return dist[t];
}

int main(void) {
  int i, flag;
  for (i = 0; i < 8; i++) scanf("%d", &s1[i]);
  for (i = 0; i < 8; i++) scanf("%d", &t1[i]);
  for (flag = 1, i = 0; i < 8; i++) flag &= (s1[i] == t1[i]);
  vert[s1] = 0; vert[t1] = 1; n = 2;
  printf("%d\n", flag ? 0 : dijkstra(0, 1));
  return 0;
}
