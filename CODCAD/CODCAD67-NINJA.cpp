#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAXN 2123

int p, n, peso[MAXN], prote[MAXN], memo[MAXN][MAXN];

int pd(int i, int lim){
  if(i == n || lim <= 0) return 0;
  if(memo[i][lim] != -1) return memo[i][lim];
  if(lim - peso[i] < 0) return memo[i][lim] = pd(i+1, lim);
  return memo[i][lim] = max(pd(i+1, lim), prote[i] + pd(i+1, lim - peso[i]));
}

int main(void){
  int i;
  memset(memo, -1, sizeof(memo));
  scanf("%d %d", &p, &n);
  for(i = 0; i < n; i++) scanf("%d %d", &peso[i], &prote[i]);
  printf("%d\n", pd(0, p));

  return 0;
}
