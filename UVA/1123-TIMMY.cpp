#include <bits/stdc++.h>

using namespace std;

const int MAXV = 312;
const int INF = 112345678;
int graph[MAXV][MAXV];
int n, m, c, k;

int dijkstra(int s, int t){
  int vis[MAXV], dist[MAXV];
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < MAXV; i++) dist[i] = INF;
  dist[s] = 0;

  priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int> > > q;
  q.push(make_pair(dist[s], s));

  while(!q.empty()){
    pair<int, int> curr = q.top();
    q.pop();
    
    if(vis[curr.second]) continue;
    vis[curr.second] = 1;
    
    for(int i = 0; i < n; i++){
      int v = i;
      int cost = graph[curr.second][v];
      if(cost == -1) continue;
      
      if(v <= c-1){
	int sum = 0, ant = v;
	for(int j = v+1; j <= c-1; j++){
	  sum += graph[ant][j];
	  ant = j;
	}
	dist[t] = min(dist[t], dist[curr.second] + sum + graph[curr.second][v]);
      }
      
      else if(dist[curr.second]+cost < dist[v]){
	dist[v] = dist[curr.second]+cost;
	q.push(make_pair(dist[v], v));
      }
    }
  }
  return dist[t];
}

int main(void){
  ios::sync_with_stdio(false);
  while(cin >> n >> m >> c >> k, n){
    memset(graph, -1, sizeof(graph));
    int u, v, cost;
    for(int i = 0; i < m; i++){
      cin >> u >> v >> cost;
      graph[u][v] = cost;
      graph[v][u] = cost;
    }

    int ans = dijkstra(k, c-1);
    cout << ans << "\n";
  }
  return 0;
}
