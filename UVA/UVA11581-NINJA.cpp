#include <stdio.h>

#define MAX 5
#define valido(i, j) (i >= 0 && i < 3 && j >= 0 && j < 3)

int grid[MAX][MAX], tmp[MAX][MAX];

int zeros(){
  int i, j, ans = 0;

  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      ans |= grid[i][j];
  return !ans;
}

int main(void){
  int n, ans, i, j, sum, t;
  char c;
  
  scanf("%d", &n);
  getchar();
  while(n--){
    getchar();
    for(i = 0 ; i < 3; i++){
      for(j = 0; j < 3; j++){
	scanf("%c", &c);
	grid[i][j] = c - '0';
      }
      getchar();
    }
	
    for(ans = -1; !zeros(); ans++){
      for(i = 0; i < 3; i++){
	for(j = 0; j < 3; j++){
	  tmp[i][j] = grid[i][j];
	  //printf("%d", tmp[i][j]);
	}
	//printf("\n");
      }
      //printf("\n");
      for(i = 0; i < 3; i++)
	for(j = 0; j < 3; j++){
	  sum = 0; 
	  if(valido(i+1, j)) sum += tmp[i+1][j];
	  if(valido(i, j+1)) sum += tmp[i][j+1];
	  if(valido(i-1, j)) sum += tmp[i-1][j];
	  if(valido(i, j-1)) sum += tmp[i][j-1];
	  grid[i][j] = sum % 2;
	}
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
