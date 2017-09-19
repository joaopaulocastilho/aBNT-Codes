#include<stdio.h>

typedef long long ll;

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll mmc(ll a, ll b) { return a * (b / gcd(a, b)); }

int main(void) {
  ll i, n, l, c, ma, resp, tmp, maior;
  scanf("%lld %lld", &n, &l);
  scanf("%lld", &c);
  ma = c;
  for (i = 1; i < n; i++) {
    scanf("%lld", &c);
    ma = mmc(c, ma);
  }
  for (maior = ma, resp = 1, i = 1; i <= l; i++) {
    tmp = mmc(i, ma);
    if (tmp > maior && tmp <= l) { resp = i; maior = tmp; }
  }
  printf("%lld\n", resp);
  return 0;
}
