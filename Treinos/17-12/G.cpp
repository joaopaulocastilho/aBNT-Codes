#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define MAX 1123
#define INF 11234567890123

typedef long long ll;
typedef pair<int, int>ii;
typedef pair<ll, int>li;
typedef vector<ii>vii;
typedef vector<vii> vvii;

int tempo_sala[MAX], s, c;

ll dijkstra(vvii &LG, int s, int t) {
  ll dist[MAX], ret = INF;
  int vis[MAX], i, current, first = 1;
  for (i = 0; i < s; i++) { dist[i] = INF; vis[i] = 0; }
  dist[s] = tempo_sala[s];
  priority_queue <li, vector<li>, greater<li> >pq;
  pq.push(li(dist[s], s));
  while (!pq.empty()) {
    current = pq.top().second; pq.pop();
    if (vis[current]) continue;
    vis[current] = 1;
    for (i = 0; i < (int)LG[current].size(); i++) {
      int v = LG[current][i].first;
      int peso = LG[current][i].second;
      //if (v == t) {
      //dist[v] = dist[current] + peso;
      // pq.push(li(dist[v], v));
      //}
      if (!vis[v] && dist[v] > dist[current] + peso) {
        if (v == t) ret = min(ret, dist[current] + peso);
        dist[v] = dist[current] + peso;
        pq.push(li(dist[v], v));
      }
    }
    if (current == t) {
      vis[current] = 0;
      dist[current] = INF;
      //first = 0;
    }
  }
  return ret;
}

int main(void) {
  int i, a, b, peso;
  ll resp = INF;
  scanf("%d %d", &s, &c);
  vvii LG(s);
  for (i = 0; i < s; i++) scanf("%d", &tempo_sala[i]);
  for (i = 0; i < c; i++) {
    scanf("%d %d %d", &a, &b, &peso); a--; b--;
    LG[a].push_back(ii(b, peso + tempo_sala[b]));
  }
  for (i = 0; i < s; i++)
    resp = min(resp, dijkstra(LG, i, i));
  printf("%lld\n", resp);
  return 0;
}
