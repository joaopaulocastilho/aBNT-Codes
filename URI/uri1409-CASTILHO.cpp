#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define MAXM 1123
#define MAXG 1123456
#define INF 1123456789
#define LINF (ll)1123456789012

typedef pair<int, int> ii;
typedef pair<long long, int> li;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;

typedef struct{
  int damage, cost;
} magic_t;

int m, n, costs[MAXG];
int memo[MAXM][MAXM];
magic_t magics[MAXM];

int pd(int i, int v){
  if(memo[i][v] != -1) return memo[i][v];
  if(v <= 0) return 0;
  if(i >= m) return INF;
  return memo[i][v] = min(pd(i, v - magics[i].damage) + magics[i].cost,
                          pd(i + 1, v));
}

ll dijkstra(int s, int t, vii &LG){
  int i, u, v, vis[MAXM];
  ll dist[MAXM];
  for(i = 0; i < n; i++) dist[i] = LINF;
  memset(vis, 0, sizeof(vis));
  dist[s] = costs[s];
  priority_queue< li, vector<li>, greater<li> > pq;
  pq.push(li(costs[s], s));
  while(!pq.empty()){
    u = pq.top().second;
    pq.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(i = 0; i < (int) LG[u].size(); i++){
      v = LG[u][i];
      if(dist[u] + costs[v] < dist[v]){
        dist[v] = dist[u] + costs[v];
        pq.push(li(dist[v], v));
      }
    }
  }
  return dist[t] == LINF ? -1 : dist[t];
}

int main(void) {
  int i, g, k, u, v, hall, hp;

  while(scanf("%d %d %d %d", &m, &n, &g, &k), m){
    vii LG(n);
    memset(costs, 0, sizeof(costs));
    for(i = 0; i < m; i++)
      scanf("%d %d", &magics[i].cost, &magics[i].damage);
    for(i = 0; i < g; i++){
      scanf("%d %d", &u, &v); u--; v--;
      LG[u].push_back(v);
      LG[v].push_back(u);
    }
    memset(memo, -1, sizeof(memo));
    for(i = 0; i < k; i++){
      scanf("%d %d", &hall, &hp); hall--;
      costs[hall] += pd(0, hp);
    }
    printf("%lld\n", dijkstra(0, n-1, LG));
  }
  return 0;
}
