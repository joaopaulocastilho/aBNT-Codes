#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int i, j, n, x, y, ans, forest[MAX][MAX], species[MAX];

  memset(species, 0, sizeof(species));
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      scanf("%d", &forest[i][j]);
      //printf("%d", forest[i][j]);
    }
    //printf("\n");
  }
  for(ans = i = 0; i < 2*n; i++){
    scanf("%d %d", &x, &y); x--; y--;
    if(species[forest[x][y]]) continue;
    species[forest[x][y]] = 1;
    ans++;
  }
  printf("%d\n", ans);

  return 0;
}
