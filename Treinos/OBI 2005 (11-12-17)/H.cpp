#include <cstdio>
#include <cstring>

#define MAX 112

int e, l, vtx, eg[MAX][MAX], vis[MAX];

void dfs(int u){
  vis[u] = 1; vtx++;
  for(int i = 1; i <= e; i++){
    if(eg[u][i] && !vis[i]){
      dfs(i);
    }
  }
}

int main(void){
  int a, b;
  int count = 0;
  while(scanf("%d %d", &e, &l), e){
    count++;
    memset(eg, 0, sizeof(eg));
    memset(vis, 0, sizeof(vis));
    vtx = 0;
    for(int i = 0; i < l; i++){
      scanf("%d %d", &a, &b);
      eg[a][b] = 1;
      eg[b][a] = 1;
    }
    dfs(1);
    printf("Teste %d\n", count);
    printf("%s\n\n", vtx == e ? "normal" : "falha");
  }
  return 0;
}
