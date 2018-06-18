#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 112345
#define INF 1123456789

long long int memo[2][MAX][2];      
int matrix[2][MAX], tc;

int main(void){
  scanf("%d", &tc);
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < tc; j++){
      scanf("%d", &matrix[i][j]);
    }
  memo[0][0][tc-1] = memo[1][0][tc-1] = matrix[0][tc-1] + matrix[1][tc-1];
  memo[0][1][tc-1] = memo[1][1][tc-1] = matrix[1][tc-1];

  for(int i = tc-2; i >= 0; i--){
    for(int j = 0; j < 2; j++){
      memo[0][j][i] = matrix[j][i] + min(memo[1][j][i+1] , memo[0][((j+1)%2)][i+1] + matrix[((j+1)%2)][i]);
      memo[1][j][i] = matrix[j][i] + max(memo[0][j][i+1] , memo[1][((j+1)%2)][i+1] + matrix[((j+1)%2)][i]);
    }
  }
  printf("%lld\n", memo[0][0][0]);
  return 0;
}
