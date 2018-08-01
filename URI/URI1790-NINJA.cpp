#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 61

int tempo, pontes, c, p, AG[MAX][MAX], low[MAX], vis[MAX], d[MAX];

void dfs(int u, int p){
  int v;
  vis[u] = 1;
  d[u] = low[u] = tempo++;
  for(v = 0; v < c; v++)
    if(AG[u][v] && !vis[v]){
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if(low[v] > d[u]) pontes++;
    }
    else if(AG[u][v] && v != p) low[u] = min(low[u], low[v]);
}

int main(void){
  int u, v;

  while(scanf("%d %d", &c, &p) != EOF){
    memset(AG, 0, sizeof(AG));
    memset(vis, 0, sizeof(vis));
    tempo = pontes = 0;
    while(p--){
      scanf("%d %d", &u, &v); u--; v--;
      AG[u][v] = AG[v][u] = 1;
    }
    dfs(0, 0);
    printf("%d\n", pontes);
  }

  return 0;
}
