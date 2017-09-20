#include <stdio.h>

#define MAX 100

#define valido(i, j) (i >= 0 && j >= 0 && i < n && j < m)

int n, m, in[MAX][MAX];

int getsum(int i, int j){
  int ans = 0;
  if(valido(i+1, j)) ans += in[i+1][j];
  if(valido(i, j+1)) ans += in[i][j+1];
  if(valido(i-1, j)) ans += in[i-1][j];
  if(valido(i, j-1)) ans += in[i][j-1];
  return ans;
}

int main(void){

  while(scanf("%d %d", &n, &m) != EOF){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) scanf("%d", &in[i][j]);

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++) printf("%d", in[i][j] ? 9 : getsum(i, j));
      printf("\n");
    }
  }

  return 0;
}
