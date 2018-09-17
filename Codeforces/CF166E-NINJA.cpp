#include <bits/stdc++.h>

const int P = 1000000007;
const int MAXV = 11234567;

long long memo[2][MAXV];

int main(void){
  int n;
  
  scanf("%d", &n);

  memo[1][0] = 1;
  for(int i = 1; i < MAXV; i++){
    memo[1][i] = (3 * memo[0][i-1]) % P; 
    memo[0][i] = (2 * memo[0][i-1] + memo[1][i-1]) % P;
  }
  printf("%lld\n", memo[1][n]);
  
  return 0;
}
