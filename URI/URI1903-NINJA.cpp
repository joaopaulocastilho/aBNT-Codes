//PROVAVELMENTE PRECISA DE VECTOR
#include <stdio.h>
#define MAX 112345

char AG[MAX][MAX],PT[MAX][MAX];

int main(void){
	int N,M,u,v,i,j;
	scanf("%d %d",&N,&M);
	
	for(i = 0;i<=N;i++)
		for(j = 0;j<=N;j++) AG[i][j] = PT[i][j] = 0;
	
	
	while(M--){
		scanf("%d %d",&u,&v);
		AG[u][v] = 1;
	}
	
for(i = 0;i<=N;i++){
		for(j = 0;j<=N;j++) printf("%d ",AG[i][j]);
printf("\n");
}			
	
	
	return 0;
}
