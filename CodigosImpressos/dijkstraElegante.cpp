#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

#define MAX 1123
using namespace std;

typedef pair<int, int> ii;

int n, w, adj[MAX][MAX], dist[MAX];

void dijkstra(int v){
  int d;
  priority_queue <ii, vector<ii>, greater<ii>> pq;
  pq.push(ii(0, v));
  while(!pq.empty()){
    v = pq.top().second;
    d = pq.top().first;
    pq.pop();
    if(dist[v] != -1) continue;
    dist[v] = d;
    for(int w = 0; w < n; w++)
      if(adj[v][w] != -1 && dist[w] == -1) pq.push(ii(d + adj[v][w], w));
  }
}

int main(void){
  int m, u, v, w;

  memset(adj, -1, sizeof(adj));
  memset(dist, -1, sizeof(dist));
  scanf("%d %d", &n, &m);
  while(m--){
    scanf("%d %d %d", &u, &v, &w); u--; v--;
    adj[u][v] = adj[v][u] = w;
  }
  dijkstra(0);
  printf("Distancias: ");
  for(int i = 0; i < n; i++) printf("%d ", dist[i]);
  printf("\n");

  return 0;
}
