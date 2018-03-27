#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define MAX 21234
#define INF 112345678

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;

int n;
vii al(MAX);

int dijkstra(int s, int t){
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  int i, u, v, w, dist[MAX], vis[MAX];

  for(i = 0; i < 2*n; i++){ dist[i] = INF; vis[i] = 0; }
  pq.push(ii(0, s));
  dist[s] = 0;
  while(!pq.empty()){
    u = pq.top().second;
    pq.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(i = 0; i < (int)al[u].size(); i++){
      v = al[u][i].first; w = al[u][i].second;
      if(dist[v] > dist[u] + w){
	dist[v] = dist[u] + w;
	pq.push(ii(dist[v], v));
      }
    }
  }
  return dist[t] == INF ? -1 : dist[t];
}

int main(void){
  int i, m, u, v, w;

  scanf("%d %d", &n, &m);
  for(i = 0; i < m; i++){
    scanf("%d %d %d", &u, &v, &w); u--; v--;
    al[2*u].push_back(ii(2*v+1, w)); al[2*u+1].push_back(ii(2*v, w));
    al[2*v].push_back(ii(2*u+1, w)); al[2*v+1].push_back(ii(2*u, w));
  }
  /*
  for(i = 0; i < 2*n; i++){
    printf("%d -> ", (i/2)+1);
    for(int j = 0; j < al[i].size(); j++) printf("(%d,%d) ", al[i][j].first/2+1, al[i][j].second);
    printf("\n");
  }
  */
  printf("%d\n", dijkstra(0, 2*(n-1)));
  
  return 0;
}
