#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 512345
#define INF -112345567

int v[MAX], memo[MAX];

int pd(int i){
  if(i == 0) return v[i];
  if(memo[i] != -INF) return memo[i];
  return memo[i] = max(v[i], v[i] + pd(i-1));
}

int main(void){
  int n;
  for(int i = 0; i < MAX; i++)
    memo[i] = -INF;
  int ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }
  for(int i = n-1; i >= 0; i--)
    ans = max(ans, pd(i));
  printf("%d\n", ans);
  return 0;
}
