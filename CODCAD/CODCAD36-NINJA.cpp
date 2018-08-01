#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1123

int main(void){
  int i, j, k, n, mat[MAX][MAX], line[MAX], col[MAX], sum, ans = -1;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    line[i] = 0;
    for(j = 0; j < n; j++){
      if(i == 0) col[j] = 0;
      scanf("%d", &mat[i][j]);
      line[i] += mat[i][j];
      col[j] += mat[i][j];
    }
  }
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      ans = max(ans, line[i] + col[j] - 2*mat[i][j]);
  printf("%d\n", ans);
  return 0;
}
