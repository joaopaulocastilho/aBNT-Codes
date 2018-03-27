#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <queue>

#define MAXG 1123
#define INF (ll)1123456789012345

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;


typedef struct{
  int cost, damage;
}magic_t;

typedef struct{
  int hp, room;
}monster_t;


ll m, n, g, k, dg[MAXG], cost[MAXG], memo[MAXG][MAXG], dist[MAXG], vis[MAXG];
ii al[MAXG][MAXG];
magic_t magics[MAXG];
monster_t monsters[MAXG];

ll pd(int i, int hp){
  if(i == m) return INF;
  if(hp <= 0) return 0;
  //printf("%d %d\n\n", i, hp);
  if(memo[i][hp] != -1) return memo[i][hp];
  return memo[i][hp] = min( pd(i+1, hp), pd(i, hp - magics[i].damage) + magics[i].cost);  
}

ll dijkstra(int s, int t){
  int u, v, i;
  
  for(i = 0; i < n; i++){
    dist[i] = INF;
    vis[i] = 0;
  }
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  dist[s] = cost[s];
  pq.push(ii(cost[s], s));
  while(!pq.empty()){
    u = pq.top().second;
    pq.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(i = 0; i < dg[u]; i++){
      v = al[u][i].first;
      if(dist[u] + cost[v] < dist[v]){
	dist[v] = dist[u] + cost[v];
	pq.push(ii(dist[v], v));
      }
    }
  }
  return dist[t] == INF ? -1 : dist[t];
}

int main(void){
  int i, u, v;

  while(scanf("%lld %lld %lld %lld", &m, &n, &g, &k), m){
    memset(dg, 0, sizeof(dg));
    memset(memo, -1, sizeof(memo));
    memset(cost, 0, sizeof(cost));
    for(i = 0; i < m; i++) scanf("%d %d", &magics[i].cost, &magics[i].damage);
    for(i = 0; i < g; i++){
      scanf("%d %d", &u, &v); u--; v--;
      al[u][dg[u]++] = ii(v, -1);
      al[v][dg[v]++] = ii(u, -1);
    }
    for(i = 0; i < k; i++){
      //printf("OI\n");
      scanf("%d %d", &monsters[i].room, &monsters[i].hp); 
      cost[monsters[i].room-1] += pd(0, monsters[i].hp);
    }
    //for(i = 0; i < n; i++) printf("%d ", cost[i]); printf("\n");
    printf("%lld\n", dijkstra(0, n-1));
  }


  return 0;
}
