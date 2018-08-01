#include <stdio.h>
#include <string.h>

#define MAX 112
#define valido(i, j) (i >= 0 && i < n && j >= 0 && j < m)

int dirx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int diry[] = {0, -1, -1, -1, 0, 1, 1, 1};

int main(void){
  int newi, newj, i, j, k, ans, t, n, m, hall[MAX][MAX], univ[MAX];

  scanf("%d", &t);
  while(t--){
    memset(univ, 0, sizeof(univ));
    scanf("%d %d", &n, &m);
    for(ans = i = 0; i < n; i++)
      for(j = 0; j < m; j++) scanf("%d", &hall[i][j]);
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++)
	for(k = 0; hall[i][j] != -1 && k < 8; k++){
	  newi = i + diry[k]; newj = j + dirx[k];
	  if(valido(newi, newj) && hall[i][j] == hall[newi][newj]){
	    if(univ[hall[i][j]] == 0){
	      univ[hall[i][j]] = 1;
	      ans++;
	    }
	    break;
	  }
	}
    printf("%d\n", ans);
  }


  return 0;
}
