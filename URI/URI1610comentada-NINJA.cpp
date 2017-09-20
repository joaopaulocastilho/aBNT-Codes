#include <stdio.h>
#include <string.h>

#define MAX 11234

int AG[MAX][MAX], vis[MAX],vism[MAX], N,f,depth[MAX];

void dfsm(int u,int i){							// essa é a dfs modificada, ela recebe esse i, que é o vertice do qual eu to calculando
	int w;										// a profundidade, incrimentando no vetor global
	vism[u] = 1;
	for (w = 1; w <= N; w++){
		if (AG[u][w])
			if(!vism[w]){
				depth[i]++;
				dfsm(w,i);
			}
	}
}

void dfs(int u){
printf("Visitando o vertice %d\n",u);
	int w;
	vis[u] = 1;
	for (w = 1; w <= N; w++){
		if (AG[u][w])
			if(!vis[w]) dfs(w);
			else{
printf("Ha ciclo pois %d eh vizinho de %d\n",u,w);
				f=1;
			}
	}
}

int main(void){
	int T, M, A, B,maisf,nf,tdsvis;
	scanf("%d", &T);								//Le num de casos de teste
	while (T--){
		for (int i=1; i<=N; i++)						// zera matriz DE ADJANCENCIAS
			for (int j=1; j<=N ; j++) AG[i][j] = 0;		
		memset(vis, 0, sizeof(vis));						// zera vetor de visitados
		f =tdsvis= 0;										//zera flags
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++){ 						// lê as dependencias ( A depende de B, logo A é vizinho de B, pois B leva a A)
			scanf("%d %d", &A, &B);
			AG[B][A] = 1;
		}

for (int i=1; i<=N; i++)			//imprime a matriz de adjacencias
	for (int j=1; j<=N ; j++){
		printf("%d ",AG[i][j] );
		if (j==N) printf("\n");
	}
	
	while (!tdsvis){				//enquanto todos os vertices nao serem visitados
		maisf = nf = 0;				// zera a maior profundidade e o indice dela
		for(int i = 1;i<=N;i++){
			dfsm(i,i);				// pra todos os vertices eu rodo uma dfs modificada pra contar em quantos vertices ela chega, pra rodar a
			memset(vism,0,sizeof(vism)); //dfs de verdade a partir dela,tambem tem um vetor de visitados modificado, zerado quando calculo
		}								// a profundidade de cada vertice
		for(int i = 1;i<=N;i++){
			if(depth[i] > nf && !vis[i]){		// nesse for eu varro o vetor de profundidades pra achar o que leva a mais vertices e rodar
				nf = depth[i];					// a busca a partir dele,note que se o vertice ja foi visitado pela busca principal ele é
				maisf = i;						// desconsiderado
			}
		}
		 
for (int i=1; i<=N; i++) printf("%d",depth[i]); printf("\n"); printf("vertice que leva mais longe: %d\n",maisf); //imprime os bagui
		dfs(maisf);							// roda a dfs a partir do vertice que leva mais longe
		tdsvis = 1;							// todos foram visitados até que se prove o contrario V
		for(int j=1;j<=N;j++) if (!vis[j]) tdsvis = 0; //                                        aqui
		memset(depth,0, sizeof(depth));		// zera o vetor de profundidades para o proximo componente conexo do grafo
	}
		
		
		f ? printf("SIM\n") : printf("NAO\n");
	}
	return 0;
}
