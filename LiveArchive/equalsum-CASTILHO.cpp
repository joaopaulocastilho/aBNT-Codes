#include <bits/stdc++.h>

using namespace std;

const int MAXN = 22;
const int MAXK = 13;
const int MAXS = 157;

int n, k, s, memo[MAXN][MAXK][MAXS];

int dp(int i, int q, int si) {
  if (q == k && si == s) return 1;
  if (q == k || i > n) return 0;
  if (memo[i][q][si] != -1) return memo[i][q][si];
  return memo[i][q][si] = dp(i + 1, q, si) + dp(i + 1, q + 1, si + i);
}

int main(void) {
  while (scanf("%d %d %d", &n, &k, &s), n) {
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(1, 0, 0));
  }
  return 0;
}
