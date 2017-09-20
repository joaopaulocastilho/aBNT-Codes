#include <stdio.h>

int matriz[5][5];

void dfs(int i,int j){
	matriz[i][j] = 2;
	if(i+1 < 5 && !matriz[i+1][j]) dfs(i+1,j);
	if(i-1 >= 0 && !matriz[i-1][j]) dfs(i-1,j);
	if(j+1 < 5 && !matriz[i][j+1]) dfs(i,j+1);
	if(j-1 >= 0 && !matriz[i][j-1]) dfs(i,j-1); 
}

int main(void){
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		for(i=0;i<5;i++)
			for(j=0;j<5;j++) scanf("%d",&matriz[i][j]);
			
		dfs(0,0);
		matriz[4][4] == 2 ? printf("COPS\n") : printf("ROBBERS\n");
	}
	return 0;
}
