#include <cstdio>

int ans[3][3];

void troca(int i, int j){
  if(i < 2)
    ans[i + 1][j] = (ans[i + 1][j] == 0) ? 1 : 0;
  if(i > 0)
    ans[i - 1][j] = (ans[i-1][j] == 0) ? 1 : 0;
  if(j < 2)
    ans[i][j+1] = (ans[i][j+1] == 0) ? 1 : 0;
  if(j > 0)
    ans[i][j-1] = (ans[i][j-1] == 0) ? 1 : 0;
  ans[i][j] = ans[i][j] == 0 ? 1 : 0;
}

int main(void){
  int matrix[3][3];

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      ans[i][j] = 1;
  
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      scanf("%d", &matrix[i][j]);
  
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(matrix[i][j] % 2 != 0)
	troca(i, j);

  for(int i = 0; i < 3; i++)
    printf("%d%d%d\n", ans[i][0], ans[i][1], ans[i][2]);
  return 0;
}
