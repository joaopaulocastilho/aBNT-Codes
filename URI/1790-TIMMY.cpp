#include <iostream>
#include <cstring>

using namespace std;

#define MAX 51

int adj[MAX][MAX], c, count;
int disc[MAX], low[MAX], vis[MAX], parent[MAX];

void dfs(int v, int time){
  vis[v] = 1;
  disc[v] = low[v] = time+1;
  int child = 0;
  for(int i = 0; i < c; i++){
    if(adj[v][i] == 1){
      if(vis[i] == -1){
	child++;
	parent[i] = v;
	dfs(i, time+1);
	low[v] = min(low[v], low[i]);
	if(low[i] > disc[v])
	  count++;
      }
      else if(parent[v] != i){
	low[v] = min(low[v], disc[i]);
      }
    }
  }
}

int main(void){
  int p;
  while(cin >> c >> p){
    int time = 0;
    count = 0;
    memset(adj, 0, sizeof(adj));
    for(int i = 0; i < p; i++){
      int u, v; cin >> u >> v;
      adj[--u][--v] = 1;
      adj[v][u] = 1;
    }
    memset(vis, -1, sizeof(vis));
    memset(vis, -1, sizeof(disc));
    memset(vis, -1, sizeof(low));
    memset(vis, -1, sizeof(parent));
    dfs(0, time+1);
    cout << count << endl;
  }
  return 0;
}
