#include <stdio.h>

#define MAX 52

int main(void){
  int i, j, n, sum, ans = 1, nsum, mat[MAX][MAX];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    for(nsum = j = 0; j < n; j++){
      scanf("%d", &mat[i][j]);
      nsum += mat[i][j];
    }
    if(i == 0) sum = nsum;
    else ans = nsum == sum;
  }
  //printf("->%d %d\n", sum, ans);
  for(i = 0; i < n; i++){
    for(nsum = j = 0; j < n; j++) nsum += mat[j][i];
    ans = nsum  == sum;
  }
  //printf("->%d %d\n", sum, ans);
  for(nsum = i = 0; i < n; i++) nsum += mat[i][i];
  ans = nsum == sum;
  //printf("->%d %d\n", sum, ans);
  for(nsum = i = 0, j = n-1; i < n; i++, j--){
    //printf("%d\n", mat[i][j]);
    nsum += mat[i][j];
  }
  ans = nsum == sum;

  printf("%d\n", ans ? sum : -1);
  
  return 0;
}
