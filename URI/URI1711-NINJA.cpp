#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 11234
#define MAXX 112
#define INF 112345678

typedef struct{
  int v, w, forb;
}node_t;

typedef pair<int, int> ii;

int s, t, orig, tam, tempo = 0, dg[MAX], cicost[MAX], vis[MAX], low[MAX], d[MAX];
node_t AL[MAX][MAXX];

void dfs(int u, int p){
  int i, v, k;
  vis[u] = 1;
  d[u] = low[u] = tempo++;
  for(i = 0; i < dg[u]; i++){
    v = AL[u][i].v;
    if(!vis[v]){
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if(low[v] > d[u]){ // ponte
	for(k = 0; k < d[v]; k++) if(AL[v][k].v == u) break;
	AL[u][i].forb = AL[v][k].forb = 1;
	//printf("A aresta %d -> %d foi proibida\n", u+1, v+1);
      }
    }
    else if(v != p) low[u] = min(low[u], d[v]); 
  }
}

int dfs2(int u, int p, int sz){
  int i, v, last = 1;
  //printf("u %d, sz: %d\n", u+1, sz);
  vis[u] = 1;
  for(i = 0; i < dg[u]; i++){
    v = AL[u][i].v;
    //printf("Considerando %d\n", v+1);
    if(!vis[v] && !AL[u][i].forb){
      //printf("Passando %d para o %d\n", sz + AL[u][i].w, v+1);
      sz = dfs2(v, u, sz + AL[u][i].w);
      last = 0;
    }
    else if(v != p && !AL[u][i].forb && last){
      sz += AL[u][i].w;
      //printf("Somou uma aresta de retorno %d -> %d com custo %d\n", u+1, AL[u][i].v+1, AL[u][i].w);
    }
  }
  return cicost[u] = sz;
}

int dijkstra(int orig){
  int i, dist[MAX], ans = INF;
  memset(vis, 0, sizeof(vis));
  for(i = 0; i < s; i++) dist[i] = INF;
  dist[orig] = 0;
  priority_queue<ii, vector<ii>, greater<ii> > q;
  q.push(ii(0, orig));
  while(!q.empty()){
    int u = q.top().second;
    int cdist = q.top().first;
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    if(cicost[u] && cicost[u] >= tam) ans = min(ans, 2*dist[u] + cicost[u]);
    for(i = 0; i < dg[u]; i++){
      int v = AL[u][i].v;
      int w = AL[u][i].w;
      if(!vis[v] && dist[v] > dist[u] + w){
	dist[v] = dist[u] + w;
	q.push(ii(dist[v], v));
      }
    }
  }
  return ans != INF ? ans : -1;
}

int main(void){
  int i, u, v, w, q;
  
  while(scanf("%d %d", &s, &t) != EOF){
    memset(dg, 0, sizeof(dg));
    memset(vis, 0, sizeof(vis));
    //memset(cicost, -1, sizeof(cicost));
    for(i = 0; i < t; i++){
      scanf("%d %d %d", &u, &v, &w); u--; v--;
      AL[u][dg[u]].v = v;
      AL[v][dg[v]].v = u;
      AL[u][dg[u]].w = AL[v][dg[v]].w = w;
      AL[u][dg[u]++].forb = AL[v][dg[v]++].forb = 0;
      //printf("%d <-> %d : %d\n", v+1, AL[v][dg[v]-1].v+1, AL[v][dg[v]-1].w); 
    }
    dfs(0, 0);
    memset(vis, 0, sizeof(vis));
    for(i = 0; i < s; i++){
      if(!vis[i]) dfs2(i, 0, 0);
      //printf("Componente do %d com %d\n", i+1, cicost[i]);
    }
    //printf("\n");
    scanf("%d", &q);
    while(q--){
      scanf("%d %d", &orig, &tam);
      printf("%d\n", dijkstra(orig-1));
    }
  }

  return 0;
}
