#include <bits/stdc++.h>

const int MAXN = 21;
const int MAXK = 11;
const int MAXS = 212;

int n, k, s, memo[MAXN][MAXS][MAXK];

int pd(int i, int sum, int tam){
  if(sum == s && tam == k) return 1;
  if(i > n || tam == k) return 0;
  if(memo[i][sum][tam] != -1) return memo[i][sum][tam];
  else return memo[i][sum][tam] = pd(i+1, sum, tam) + pd(i+1, sum+i, tam+1); 
}

int main(void){
  
  while(scanf("%d %d %d", &n, &k, &s), n){
    memset(memo, -1, sizeof(memo));
    printf("%d\n", pd(1, 0, 0));
  } 
	
  return 0;
}
