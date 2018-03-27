#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAX 1123
#define INF 112345678

int main(void){
  int i, j, k, l, n, minlo, maxglo;
  char grid[MAX][MAX];
  
  while(scanf("%d ", &n) != EOF){
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++)
	scanf("%c", &grid[i][j]);
      getchar();
    }
    for(maxglo = -INF, i = 0; i < n; i++)
      for(j = 0; j < n; j++)
	if(grid[i][j] == '1'){
	  //printf("%d %d\n", i, j);
	  for(minlo = INF, k = 0; k < n; k++)
	    for(l = 0; l < n; l++)
	      if(grid[k][l] == '3') minlo = min(minlo, abs(i-l) + abs(j-k));
	  maxglo = max(maxglo, minlo);
	}
    printf("%d\n", maxglo);
  }

  return 0;
}
