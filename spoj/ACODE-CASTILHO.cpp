#include <bits/stdc++.h>

using namespace std;

#define valido(x) ((x) >= 0 && (x) < n)

const int MAXV = 5123;

typedef long long ll;

int n;
ll memo[MAXV];
char s[MAXV];

ll dp(int i) {
  int x, n1, n2;
  if (i <= 0) return 1;
  if (memo[i] != -1) return memo[i];
  n1 = s[i - 1] - '0'; n2 = s[i] - '0';
  x = n1 * 10 + n2;
  if (x == 10 || x == 20) return memo[i] = dp(i - 2);
  if (x > 9 && x <= 26) return memo[i] = dp(i - 1) + dp(i - 2);
  return memo[i] = dp(i - 1);
}

int main(void) {
  int i, flag;
  while (scanf("%s ", s)) {
    if (strlen(s) == 1 && s[0] == '0') break;
    n = strlen(s);
    for (flag = 0, i = 1; !flag && i < n; i++)
      if (s[i] == '0' && s[i - 1] == '0') flag = 1;
    if (flag) { printf("0\n"); continue; }
    memset(memo, -1, sizeof(memo));
    printf("%lld\n", dp(n - 1));
  }
  return 0;
}
