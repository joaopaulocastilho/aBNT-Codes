#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int MAX = 1123;
const int INF = 112345678;

int n, m, dist[MAX];
vector<ii> AL[MAX];

int dijkstra(void){
  int i, u, d;
  
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  for(i = 0; i <= n+1; i++) dist[i] = INF;
  pq.push(ii(0, 0));
  while(!pq.empty()){
    u = pq.top().second;
    d = pq.top().first;
    pq.pop();
    if(dist[u] != INF) continue;
    dist[u] = d;
    for(i = 0; i < AL[u].size(); i++)
      pq.push(ii(d + AL[u][i].first, AL[u][i].second));
  }
  return dist[n+1];
}

int main(void){
  int u, v, w, i;
  
  scanf("%d %d", &n, &m);
  for(i = 0; i < m; i++){
    scanf("%d %d %d", &u, &v, &w);
    AL[u].push_back(ii(w, v));
    AL[v].push_back(ii(w, u));
  }
  printf("%d\n", dijkstra());
  
  return 0;
}
