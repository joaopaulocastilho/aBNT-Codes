#include <bits/stdc++.h>

using namespace std;

const int MAX = 1123;

int n, m, memo[MAX][MAX], v1[MAX], v2[MAX];

int lcs(int i, int j){
  if(i < 0 || j < 0) return 0;
  if(memo[i][j] != -1) return memo[i][j];
  if(v1[i] == v2[j]) return memo[i][j] = lcs(i-1, j-1) + 1;
  return memo[i][j] = max(lcs(i, j-1), lcs(i-1, j));
}

int main(void){
  int i, res;

  memset(memo, -1, sizeof(memo));
  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++) scanf("%d", &v1[i]);
  for(i = 0; i < m; i++) scanf("%d", &v2[i]);

  res = lcs(n-1, m-1);
  printf("%d %d\n", n-res, m-res);
  
  return 0;
}
