#include <stdio.h>
#include <string.h>

#define MAX 11234

int AL[MAX][MAX], vis[MAX], N,f,pilha[MAX],fim,raiz[MAX];

void dfs(int u){
	int w,i;
	pilha[fim++] = u;
for(i=0;i<fim;i++) printf("%d ",pilha[i]); printf("\n");
	vis[u] = 1;
printf("Visitando o vertice %d\n",u);
	for (w = 1; w <= AL[u][0]; w++) for(i=0;i<fim;i++) if (AL[u][w] == pilha[i]) f=1;
	for (w = 1; w <= AL[u][0]; w++)	if(!vis[AL[u][w]]) dfs(AL[u][w]);
	fim--;
}

int main(void){
	int T, M, A, B,i,j;
	scanf("%d", &T);
	while (T--){
		f=fim= 0;
		scanf("%d %d", &N, &M);
		for (i=1; i<=N; i++){
			vis[i] = 0;
			AL[i][0] = 0;
			raiz[i] = 1;
		}
			
		for (i = 0; i < M; i++){ 
			scanf("%d %d", &A, &B);
			AL[B][	++AL[B][0]  ] = A;
			raiz[A] = 0;
		}

for (i=1; i<=N; i++){			//imprime a "Lista de adjacencias"
	printf("Vizinhos do %d : ",i);
	for (j=1; j<=AL[i][0] ; j++){
		printf("%d ",AL[i][j] );
	}
	printf("\n");
}	
		for(i=1;i<=N;i++) if (raiz[i]) dfs(i);
		for(i=1;i<=N;i++) if (!vis[i]) f = 1;
		
		f ? printf("SIM\n") : printf("NAO\n");
	}
	return 0;
}
