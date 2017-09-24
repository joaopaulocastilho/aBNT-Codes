#include <stdio.h>
#include <string.h>

#define MAXR 112
#define MAXN 1000

int adj[MAXN][MAXN], dg[MAXN], vis[MAXN], ans;

void dfs(int v){
  vis[v] = 1;
  ans++;
  for(int i = 0; i < dg[v]; i++)
    if(!vis[adj[v][i]] && dg[adj[v][i]] != -1)
      dfs(adj[v][i]);
}


int main(void){
  int k, n, r, sum, usertarg, namigos, nume = 1, flag = 1;
  int newcat[MAXR], usercat[MAXR];

  scanf("%d", &k);
  while(k--){
    ans = 0;
    memset(dg, -1, sizeof(dg));
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &n, &r);
    for(int i = 0; i < r; i++) scanf("%d", &newcat[i]);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < r; j++) scanf("%d", &usercat[j]);
      scanf("%d %d", &usertarg, &namigos);
      for(int j = 0; j < namigos; j++){ scanf("%d", &adj[i][j]); adj[i][j]--;}
      sum = 0;
      for(int j = 0; j < r; j++) sum += newcat[j] * usercat[j];
      dg[i] = usertarg == sum ? namigos : -1;
    }
    if(dg[0] != -1) dfs(0);
    if(flag) flag = 0;
    printf("Data Set %d:\n", nume++ );
    printf("%d\n\n",ans);
  }




  return 0;
}
