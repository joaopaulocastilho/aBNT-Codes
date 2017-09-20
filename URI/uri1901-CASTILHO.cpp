#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int grid[MAX][MAX], n, i, j, coletados[MAX], l, c, cont;
  scanf("%d", &n);
  cont=0;
  memset(coletados, 0, sizeof(coletados));
  for(i=1; i<=n; i++)
    for(j=1; j<=n; j++) scanf("%d", &grid[i][j]);
  for(i=0; i<n*2; i++){
    scanf("%d%d", &l, &c);
    coletados[grid[l][c]]++;
  }
  for(i=0; i<MAX; i++) if(coletados[i]) cont++;
  printf("%d\n", cont);
  return 0;
}
