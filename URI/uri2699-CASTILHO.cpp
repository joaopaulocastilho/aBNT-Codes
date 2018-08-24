#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

int n, tams, memo[MAXV][MAXV], ans[MAXV];
char s[MAXV];

int expbin(int a, int b, int m) {
  int y;
  if (b == 0) return 1;
  if (b & 1) return ((a % m) * expbin(a, b - 1, m) % m);
  y = expbin(a, b >> 1, m);
  return (y * y) % m;
}

int dp(int i, int g) {
  int j, eb, &est = memo[i][g];
  if (i == tams) return (g == 0);
  if (est != -1) return est;
  if (s[i] != '?') {
    eb = (((s[i] - '0') % n) * expbin(10, tams - i - 1, n)) % n;
    ans[i] = s[i] - '0';
    return est = dp(i + 1, (eb + g) % n);
  }
  est = 0;
  for (j = (i == 0); j < 10; j++) {
    eb = ((j % n) * expbin(10, tams - i - 1, n)) % n;
    est |= dp(i + 1, (eb + g) % n);
    if (est && ans[i] == -1) ans[i] = j;
  }
  return est;
}

int main(void) {
  int i;
  scanf("%s %d", s, &n); tams = strlen(s);
  memset(memo, -1, sizeof(memo));
  memset(ans, -1, sizeof(ans));
  if (dp(0, 0) == 0) printf("*\n");
  else {
    for (i = 0; i < tams; i++) printf("%d", ans[i]);
    printf("\n");
  }
  return 0;
}
