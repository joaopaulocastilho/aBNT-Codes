#include <cstdio>

#define MAX 112345

long long int memo[2][MAX][2];
int matrix[2][MAX], tc;

int pd(int i, idx j, int dec){
  if(memo[i][j][dec] != -INF) return memo[i][j][dec];
  if(i == 1 && j == tc) return memo[i][j][dec] = matrix[i][j] + matrix[i+1][j];
  if(i == 2 && j == tc) return memo[i][j][dec] = matrix[i][j];
  if(i == 2) return 0;
  usado[i][j] = 1;
  if(dec == 0){
    if(i == 0){
      if(!usado[1][j]) opt1 = pd(1, j, 1)+matrix[1][j];
      opt2 = pd(0, j+1, 1)+matrix[0][j+1];
      usado[i][j] = 0;
      return memo[i][j][dec] = min(opt1, opt2);
    }
    if(i == 1){
      if(!usado[0][j]) opt1 = pd(0, j, 1) + matrix[0][j];
      opt2 = pd(1, j+1, 1)+matrix[1][j+1];
      usado[i][j] = 0;
      return memo[i][j][dec] = min(opt1, opt2);
    }
  } 
  else{
    if(i == 0){
      if(!usado[1][j]) opt1 = pd(1, j, 0)+matrix[1][j];
      opt2 = pd(0, j+1, 0)+matrix[0][j+1];
      usado[i][j] = 0;
      return memo[i][j][dec] = max(opt1, opt2);
    }
    if(i == 1){
      if(!usado[0][j]) opt1 = pd(0, j, 0) + matrix[0][j];
      opt2 = pd(1, j+1, 0)+matrix[1][j+1];
      usado[i][j] = 0;
      return memo[i][j][dec] = max(opt1, opt2);
    }
  }
  return ans;
}

int main(void){
    
    scanf("%d", &tc);
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < tc; j++){
        scanf("%d", &matrix[i][j]);
    }
    ans = pd(0, 0, 0);
    return 0;
}
