#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define MAX 11234
#define MAXA 112
#define INF 112345678

int s, t;
int dg[MAX], dgc[MAX], disc[MAX], custo[MAX];
int low[MAX], vis[MAX], parent[MAX], vc[MAX][MAXA];
pii adj[MAX][MAXA];

void tarjan(int v, int time){
  //cout << v << " " << time << endl;
  vis[v] = 1;
  disc[v] = low[v] = time+1;
  int child = 0;
  for(int i = 0; i < dg[v]; i++){
    int u = adj[v][i].first;
    if(vis[u] == -1){
      child++;
      parent[u] = v;
      tarjan(u, time+1);
      low[v] = min(low[v], low[u]);
      if(low[u] > disc[v]){
	vc[v][dgc[v]++] = u;
	vc[u][dgc[u]++] = v;
      }
    }
    else if(parent[v] != u){
      low[v] = min(low[v], disc[u]);
    }
  }
}

int dfs(int v, int cost){
  vis[v] = 1;
  for(int i = 0; i < dg[v] && custo[v] == -1; i++){
    int u = adj[v][i].first;
    //cout << "Testanto o vertice "<< v << "->" << u << ": ";
    int proibido = 0;
    for(int j = 0; j < dgc[v]; j++)
      if(u == vc[v][j]) proibido = 1;
    if(proibido){
      //cout << "proibido" << endl;
      continue;
    }
    if(parent[v] == u){
      //cout << "pai" << endl;
      continue;
    }
    parent[u] = v;
    if(vis[u] == 1){
      custo[v] = cost + adj[v][i].second;
      //cout << "Fechei o ciclo" << endl;
      return custo[v];
    }
    else{
      //cout << "vai filhao: ";
      //cout << cost+adj[v][i].second << endl;
      custo[v] = dfs(u, cost + adj[v][i].second);
    }
  }
  return (custo[v] == -1 ? 0 : custo[v]);
}

int dijkstra(int source, int msz){
  int dist[MAX], i, resp = INF;
  memset(vis, 0, sizeof(vis));
  for(i = 0; i < s; i++) dist[i] = INF;
  dist[source] = 0;
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(pii(0, source));
  while(!pq.empty()){
    int d = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if(vis[v]) continue;
    vis[v] = 1;
    //cout << custo[v] << " " << msz << endl;
    if(custo[v] >= msz) resp = min(resp, (2*d)+custo[v]);
    for(int w = 0; w < dg[v]; w++){
      int peso = adj[v][w].second;
      int vtx = adj[v][w].first;
      //cout << vtx << endl;
      if(!vis[vtx] && dist[vtx] > dist[v]+peso){
	dist[vtx] = dist[v]+peso;
	pq.push(make_pair(dist[vtx], vtx));
      }
    }
  }
  return (resp == INF ? -1 : resp);
}

int main(void){
  while(cin >> s >> t){
    memset(dg, 0, sizeof(dg));
    memset(dgc, 0, sizeof(dgc));
    memset(vis, -1, sizeof(vis));
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    memset(parent, -1, sizeof(parent));
    memset(custo, -1, sizeof(custo));
    for(int i = 0; i < t; i++){
      int u, v, val;
      cin >> u >> v >> val;
      u--; v--;
      adj[u][dg[u]++] = pii(v, val);
      adj[v][dg[v]++] = pii(u, val);
    }
    /*for(int i = 0; i < s; i++){
      cout << i << ": ";
      for(int j = 0; j < dg[i]; j++)
	cout << "(" << adj[i][j].first << "," << adj[i][j].second << "), ";
      cout << endl;
    }
    */
    tarjan(0, 0);
    for(int i = 0; i < s; i++){
      if(custo[i] == -1){
	memset(vis, -1, sizeof(vis));
	memset(parent, -1, sizeof(parent));
	parent[i] = i;
	custo[i] = dfs(i, 0);
      }
    }/*
    for(int i = 0;i < s; i++){
      cout << i << ": " << custo[i] << endl;
    }
    for(int i = 0; i < s; i++){
      cout << i << ": ";
      for(int j = 0; j < dgc[i]; j++)
	cout << "(" << vc[i][j] << "), ";
      cout << endl;
    }*/
    int q; cin >> q;
    for(int i = 0; i < q; i++){
      int ms, msz; cin >> ms >> msz;
      ms--;
      cout << dijkstra(ms, msz) << endl;
    }
  }

  return 0;
}
