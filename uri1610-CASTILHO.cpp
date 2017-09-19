#include <stdio.h>
#include <string.h>

#define MAX 11234

int madj[MAX][MAX], tma[MAX], vis[MAX], flagp[MAX], fd;

int dfs(int n){
  int i;
  if(flagp[n]){ return 0; }
   if(vis[n]) return 1;
  vis[n]=1; flagp[n] = 1;
  for(i=0; i<tma[n]; i++){
    fd &= dfs(madj[n][i]);
  }
  flagp[n] = 0;
  return fd;
}

int main(void){
  int t, n, m, a, b, i, flagdfs;
  scanf("%d", &t);
  while(t--){
    memset(tma, 0, sizeof(tma));
    memset(vis, 0, sizeof(vis));
    memset(flagp, 0, sizeof(flagp));
    flagdfs=1; fd=1;
    scanf("%d%d", &n, &m);
    for(i=0; i<m; i++){
      scanf("%d%d", &a, &b);
      madj[a][tma[a]++] = b;
    }
    for(i=0; i<MAX; i++){
      if(tma[i] && !vis[i]) flagdfs &= dfs(i);
    }
    printf("%s\n", flagdfs ? "NAO" : "SIM");
  }
  return 0;
}
