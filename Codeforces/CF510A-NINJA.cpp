#include <stdio.h>

#define MAX 112

int main(void){
  int flag, n, m, i, j;
  char mat[MAX][MAX];

  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++) mat[i][j] = '.';
  
  for(flag = i = 0; i < n; i++){
    if(flag == 1){mat[i][m-1] = '#'; flag++; continue;}
    if(flag == 3){mat[i][0] = '#'; flag = 0; continue;}
    for(j = 0; j < m; j++) mat[i][j] = '#';
    flag++;
  }

  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++) printf("%c", mat[i][j]);
    printf("\n");
  }
  
  return 0;
}
