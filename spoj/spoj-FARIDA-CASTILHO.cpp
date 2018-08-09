#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXV = 11234;

int n, coins[MAXV];
ll memo[MAXV];

ll dp(int i) {
  if (i >= n) return 0;
  if (memo[i] != -1) return memo[i];
  return memo[i] = max(dp(i + 1), dp(i + 2) + coins[i]);
}

int main(void) {
  int t, caso, i;
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &coins[i]);
    memset(memo, -1, sizeof(memo));
    printf("Case %d: %lld\n", caso, dp(0));
  }
  return 0;
}
