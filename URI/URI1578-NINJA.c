#include <stdio.h>
#include <string.h>
#define MAX 30
typedef unsigned long long ull;

ull contadigitos(ull x){
	int i=0;
	if (x==0) return 1;
	while (x){
		x /= 10;
		i++;
	}
	return i;
}

int main() {
	int N,M,i,j,x=4,y;
	ull matriz[MAX][MAX],madig[MAX][MAX],maxcol[MAX];
	scanf ("%d",&N);
	while (N--){
		memset(maxcol,0,sizeof(maxcol));
		scanf("%d",&M);		
		for(i=0;i<M;i++)
			for(j=0;j<M;j++){
				scanf("%llu",&matriz[i][j]);
				matriz[i][j]*=matriz[i][j];
				madig[i][j] = contadigitos(matriz[i][j]);
				if (madig[i][j] > maxcol[j]) maxcol[j] = madig[i][j];
			}
		printf("Quadrado da matriz #%d:\n",x);
		x++;
		for (i=0;i<M;i++)
			for(j=0;j<M;j++){
				y = maxcol[j]- madig[i][j];
				while(y--) printf(" ");
				printf("%llu",matriz[i][j]);
				if (j== M-1) printf("\n");
				else printf(" ");
			}
		if (N ) printf("\n");
		
	}
	return 0;
}
