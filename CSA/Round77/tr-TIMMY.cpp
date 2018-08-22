#include <iostream>
#include <cstring>

using namespace std;

#define MAX 112345
#define INF 1123456789

long long int memo[2][2][MAX];      
int matrix[2][MAX], m;

long long int pd(int mm, int i, int j){
  if(memo[mm][i][j] != -1) return memo[mm][i][j];
  if(!mm)
    return memo[mm][i][j] = min(pd(1, i, j+1) + matrix[i][j], pd(0, (i+1)%2, j+1) + matrix[i][j] + matrix[(i+1)%2][j]);
  else
    return memo[mm][i][j] = max(pd(0, i, j+1) + matrix[i][j], pd(1, (i+1)%2, j+1) + matrix[i][j] + matrix[(i+1)%2][j]);
}

int main(void){
  cin >> m;
  for(int i = 0;i < 2; i++)
    for(int j= 0; j < 2; j++)
      for(int k = 0; k < m; k++)
	memo[i][j][k] = -1;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < m; j++){
      cin >> matrix[i][j];
    }
  }
  memo[0][0][m-1] = memo[1][0][m-1] = matrix[0][m-1] + matrix[1][m-1];
  memo[0][1][m-1] = memo[1][1][m-1] = matrix[1][m-1];
  cout << pd(0, 0, 0) << "\n";
  return 0;
}
