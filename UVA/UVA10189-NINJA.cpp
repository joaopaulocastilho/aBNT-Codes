#include <stdio.h>

#define MAX 112
#define valido(i, j) (i < n && i >= 0 && j < m && j >= 0)

int dirx[] = {1,  1,  0, -1, -1, -1,  0, 1};
int diry[] = {0, -1, -1, -1,  0,  1,  1, 1};

int main(void){
  int i, j, ni, nj, k, n, m, adj, field = 1;
  char tab[MAX][MAX];
  
  while(scanf("%d %d", &n, &m), n || m){
    for(i = 0; i < n; i++) scanf("%s ", tab[i]); 
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++){
	if(tab[i][j] == '*') continue;
	for(adj = k = 0; k < 8; k++){
	  ni = i + dirx[k]; nj = j + diry[k];
	  if(valido(ni, nj) && tab[ni][nj] == '*') adj++;
	}
	tab[i][j] = '0' + adj;
      }
    if(field > 1) printf("\n");
    printf("Field #%d:\n", field++);
    for(i = 0; i < n; i++) printf("%s\n", tab[i]);
  }

  return 0;
}
