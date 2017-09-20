#include <stdio.h>
#include <string.h>

int grid[5][5], visitados[5][5], fo;

void dfs(int i, int j){
  visitados[i][j] = 1;
  if(i == 4 && j == 4) fo=1;
  else{
    if(j<4 && visitados[i][j+1]==0 && grid[i][j+1]==0) dfs(i, j+1);
    if(j>0 && visitados[i][j-1]==0 && grid[i][j-1]==0) dfs(i, j-1);
    if(i<4 && visitados[i+1][j]==0 && grid[i+1][j]==0) dfs(i+1, j);
    if(i>0 && visitados[i-1][j]==0 && grid[i-1][j]==0) dfs(i-1, j);
  }
}

int main(void){
  int t, i, j;
  scanf("%d", &t);
  while(t--){
    fo = 0;
    memset(visitados, 0, sizeof(visitados));
    for(i=0; i<5; i++)
      for(j=0; j<5; j++) scanf("%d", &grid[i][j]);
    dfs(0, 0);
    if(fo) printf("COPS\n");
    else printf("ROBBERS\n");
  }
  return 0;
}
