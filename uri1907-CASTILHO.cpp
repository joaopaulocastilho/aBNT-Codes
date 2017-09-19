#include <stdio.h>
#include <string.h>

char grid[2000][2000];
int visitado[2000][2000], N, M;

void dfs(int i, int j){
	grid[i][j] = 'V';
	if(i>0   && grid[i-1][j]=='.') dfs(i-1, j);
	if(i<N-1 &&  grid[i+1][j]=='.') dfs(i+1, j);
	if(j>0 && grid[i][j-1]=='.') dfs(i, j-1);
	if(j<M-1  && grid[i][j+1]=='.') dfs(i, j+1);
}

int main(void){
	int i, j, cont=0;
	memset(visitado, 0, sizeof(visitado));
	scanf("%d%d", &N, &M);
	for(i=0; i<N; i++){
		getchar();
		for(j=0; j<M; j++)
			scanf("%c", &grid[i][j]);
	}
	for(i=0; i<N; i++)
		for(j=0; j<M; j++){
			if(grid[i][j] == '.'){
				cont++;
				dfs(i, j);
			}
		}
			

			
	printf("%d\n", cont);
	return 0;
}
