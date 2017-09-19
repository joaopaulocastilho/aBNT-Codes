#include<stdio.h>
#include<string.h>

#define PRIMO 1000000007
#define MAX 112345

typedef long long ll;

int m, n;
ll S[MAX][51];

int monta_arvore(int i, int t) {
  if (S[i][t] != -1) return S[i][t];
  if (t == 1) return S[i][t] = 1;
  if (i == m) return S[i][t] = monta_arvore(i + 1, t - 1) % PRIMO;
  if (i == n) return S[i][t] = monta_arvore(i - 1, t - 1) % PRIMO;
  return S[i][t] =
    ((monta_arvore(i + 1, t - 1) % PRIMO) +
     (monta_arvore(i - 1, t - 1) % PRIMO)) % PRIMO;
}

int main(void) {
  int i, t;
  ll resp = 0;
  memset(S, -1, sizeof(S));
  scanf("%d %d %d", &t, &m, &n);
  for (i = m; i <= n; i++) resp += monta_arvore(i, t) % PRIMO;
  printf("%lld\n", resp % PRIMO);
  return 0;
}
