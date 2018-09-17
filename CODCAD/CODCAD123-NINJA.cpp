#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int MAX = 251;
const int INF = 112345678;

int n, m, c, k, AG[MAX][MAX], dist[MAX];

int dijkstra(int s){
  int i, u, d;
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  
  memset(dist, -1, sizeof(dist));
  pq.push(ii(0, s));
  while(!pq.empty()){
    u = pq.top().second;
    d = pq.top().first;
    pq.pop();
    if(dist[u] != -1) continue;
    dist[u] = d;
    for(i = 0; i < n; i++)
      if(AG[u][i] != -1) pq.push(ii(d + AG[u][i], i));
  }
  return dist[c-1];
}

int main(void){
  int i, u, v, w, curr;
  
  while(scanf("%d %d %d %d", &n, &m, &c, &k), n){
    memset(AG, -1, sizeof(AG));
    for(i = 0; i < m; i++){
      scanf("%d %d %d", &u, &v, &w);
      AG[u][v] = AG[v][u] = w;
    }
    for(curr = 0, i = c-2; i >= 0; i--){
      curr += AG[i][i+1];
      memset(AG[i], 0, sizeof(AG[i]));
      AG[i][i+1] = AG[i+1][i] = -1;
      AG[i][c-1] = AG[c-1][i] = curr;
    }
    printf("%d\n", dijkstra(k));
  }

  return 0;
}
