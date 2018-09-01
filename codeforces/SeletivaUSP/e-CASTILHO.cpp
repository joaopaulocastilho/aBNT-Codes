#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXP = 31;

ll c[MAXP][MAXP];

void triangulo_pascal() {
  int i, j;
  memset(c, 0, sizeof(c));
  for (i = 0; i < MAXP; i++) c[i][0] = 1;
  for (i = 1; i < MAXP; i++) c[i][1] = i;
  for (i = 2; i < MAXP; i++)
    for (j = 2; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

int main(void) {
  int n, i;
  ll ans;
  scanf("%d", &n);
  triangulo_pascal();
  for (ans = 0, i = 2; i <= n; i++) ans += c[n][i];
  printf("%lld\n", ans);
  return 0;
}
