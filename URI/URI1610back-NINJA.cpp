#include <stdio.h>
#include <string.h>
  
#define MAX 11234
  
int AG[MAX][MAX], vis[MAX], N,f,pilha[MAX],fim,raiz[MAX];
  
void dfs(int u){
//printf("Visitando o vertice %d\n",u);
    int w,i;
    pilha[fim++] = u;
    vis[u] = 1;
    for (w = 1; w <= N; w++) if (AG[u][w]) for(i=0;i<fim;i++) if(w==pilha[i]) f = 1;
    for (w = 1; w <= N; w++) if (AG[u][w]) if (!vis[w]) dfs(w);
    
    fim--;
}
  
int main(void){
    int T, M, A, B,i,j;
    scanf("%d", &T);
    while (T--){		
        f = fim = 0;
        scanf("%d %d", &N, &M);
        for (i=1; i<=N; i++){
            vis[i] = 0;
            raiz[i] = 1;
            for (j=1; j<=N ; j++) AG[i][j] = 0;
        }
        for (i = 0; i < M; i++){ 
            scanf("%d %d", &A, &B);
            AG[B][A] = 1;
            raiz[A] = 0;
        }
  
        /*for (i=1; i<=N; i++)
            for (j=1; j<=N ; j++){
                printf("%d ",AG[i][j] );
                if (j==N) printf("\n");
            }*/
                  
        for(i=1; i<=N ; i++) 	if(raiz[i]) dfs(i);
        for(i=1; i<=N ; i++)	if(!vis[i]) f = 1;
        
        f ? printf("SIM\n") : printf("NAO\n");
    }
    return 0;
}
