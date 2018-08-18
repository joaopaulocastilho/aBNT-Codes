#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;
const int MAXP = 53;
const int P = 1000000007;

typedef long long ll;

int qtd[11], memo[11][12][52][52];
ll c[MAXP][MAXP];

void triangulo_pascal() {
  int i, j;
  memset(c, 0, sizeof(c));
  for (i = 0; i < MAXP; i++) c[i][0] = 1;
  for (i = 1; i < MAXP; i++) c[i][1] = i;
  for (i = 2; i < MAXP; i++)
    for (j = 2; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

ll dp(int dig, int mod, int imp, int par) {
  int novo_imp, novo_par, i;
  ll novo_mod, tmp, a1, b1, c1, ret = 0;
  if (imp < 0 || par < 0) return 0;
  if (dig == 10 && mod == 0) return 1;
  if (dig == 10) return 0;
  if (memo[dig][mod][imp][par] != -1) return memo[dig][mod][imp][par];
  for (i = 0; i <= qtd[dig]; i++) {
    novo_imp = i;
    novo_par = qtd[dig] - novo_imp;
    a1 = mod; b1 = novo_imp * dig; c1 = novo_par * dig;
    novo_mod = ((a1 % 11) + (b1 % 11) - (c1 % 11) + 11) % 11;
    tmp = ((c[imp][novo_imp] % P) * (c[par][novo_par] % P)) % P;
    tmp = (tmp * dp(dig + 1, novo_mod, imp - novo_imp, par - novo_par)) % P;
    ret = (ret + tmp) % P;
  }
  return memo[dig][mod][imp][par] = ret % P;
}

int main(void) {
  int i, tam;
  ll ans;
  char n[MAXV];
  triangulo_pascal();
  while (fgets(n, MAXV, stdin)) {
    memset(qtd, 0, sizeof(qtd));
    for (i = 0; n[i] != '\n'; i++) qtd[n[i] - '0']++;
    for (ans = 0, tam = strlen(n) - 1, i = 1; i < 10; i++) {
      if (qtd[i] == 0) continue;
      memset(memo, -1, sizeof(memo));
      qtd[i]--;
      ans = (ans + dp(0, i, tam / 2 - ((tam & 1) ? 0 : 1), tam / 2)) % P;
      qtd[i]++;
    }
    printf("%lld\n", ans % P);
  }
  return 0;
}
