#include <stdio.h>
#include <string.h>

#define MAX 1123

int n, AM[MAX][MAX], vis[MAX], ans = 1;

void dfs(int u, int cor){
    int i;
    vis[u] = cor;
    for(i = 1; i <= n; i++)
        if(AM[u][i]){
            if(!vis[i]) dfs(i, cor == 1 ? 2 : 1);
            else if(vis[i] == cor) ans = 0;
        }
    }

int main(void){
    int i, j;

    memset(vis, 0, sizeof(vis));
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d",&AM[i][j]);
            AM[i][j] = !AM[i][j];
        }
    }
    for(i = 1; i <= n; i++) if(!vis[i]) dfs(i, 1);
    if(ans) printf("Bazinga!\n");
    else printf("Fail!\n");
    return 0;
}
