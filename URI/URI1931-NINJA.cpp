#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <string.h>

#define MAXC 21234
#define INF 1123456789
//#define DEBUG

using namespace std;


typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vvpi adj(MAXC);
int c;

int dijkstra(int s, int t){
  int dist[MAXC], vis[MAXC], i;

  memset(vis, 0, sizeof(vis));
  for(i = 0; i < 2 * c; i++) dist[i] = INF;
  dist[s] = 0;
  priority_queue<pi, vpi, greater<pi>> kiwi;
  kiwi.push(make_pair(dist[s], s));
  while(!kiwi.empty()){
    pi current = kiwi.top();
    kiwi.pop();
    if(vis[current.second]) continue;
    vis[current.second] = 1;
// printf("Visitando %d\n", current.first/2 + 1);
    for(i = 0; i < (int) adj[current.second].size(); i++){
      int v = adj[current.second][i].second;
      int vpeso = adj[current.second][i].first;
      if(!vis[v] && dist[v] > dist[current.second] + vpeso){
        dist[v] = dist[current.second] + vpeso;
        kiwi.push(make_pair(dist[v], v));
      }
    }
  }
  return dist[t] == INF ? -1 : dist[t];
}

int main(void){
  int v, a, b, d;

  scanf("%d %d", &c, &v);
  while(v--){
    scanf("%d %d %d", &a, &b, &d);
    --a; --b;
    adj[2 * a + 1].push_back(make_pair(d, 2*b));
    adj[2 * b + 1].push_back(make_pair(d, 2*a));
    adj[2 * a].push_back(make_pair(d, 2*b + 1));
    adj[2 * b].push_back(make_pair(d, 2*a + 1));

  }
  #ifdef DEBUG
  for(int i = 0; i < 2 * c; i++){
    for(int j = 0; j < (int) adj[i].size(); j++)
      printf("%d %s -> %d %s com peso %d\n", i/2 + 1, i & 1 ? "impar" : "par",
          adj[i][j].second/2 + 1, adj[i][j].second & 1 ? "impar" : "par", adj[i][j].first);
  }
  #endif

  printf("%d\n", dijkstra(0, 2*c - 2));

  return 0;
}
