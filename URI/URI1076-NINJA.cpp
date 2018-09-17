#include <bits/stdc++.h>

const int MAXV = 61;

int ans, vis[MAXV], AG[MAXV][MAXV];

void dfs(int u){
  vis[u] = 1;
  for(int i = 0; i < MAXV; i++)
    if(AG[u][i] && !vis[i]){ ans++; dfs(i);}
}

int main(void){
  int t, n, m, s, u, v;
  
  scanf("%d", &t);
  while(t--){
    memset(vis, 0, sizeof(vis));
    memset(AG, 0, sizeof(AG));
    scanf("%d", &s);
    scanf("%d %d", &n, &m);
    while(m--){
      scanf("%d %d", &u, &v);
      AG[u][v] = AG[v][u] = 1;
    }
    ans = 0; dfs(s);
    printf("%d\n", 2 * ans);
  }

  return 0;
}
