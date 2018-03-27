#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 51234
#define INF -112345678

int v[MAX], memo[MAX];

int pd(int i){
  if(memo[i] != INF) return memo[i];
  if(i == 0) return memo[i] = v[i];
  return memo[i] = max(pd(i-1) + v[i], v[i]);
}

int main(void){
  int i, n, ans = -1;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &v[i]);
    memo[i] = INF;
  }
  pd(n-1);
  for(i = 0; i < n; i++){
    ans = max(ans, memo[i]);
    //printf("%d ", memo[i]);
  }
  //printf("\n");
  printf("%d\n", ans);
  
  return 0;
}
