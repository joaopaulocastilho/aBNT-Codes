#include <stdio.h>

#define MAX 112

int main(void){
  int i, j, n, num, m[MAX][MAX];

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) scanf("%d", &m[i][j]);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      scanf("%d", &num);
      printf("%s%d", j ? " " : "", num + m[i][j]);
    }
    printf("\n");
  }


  return 0;
}
