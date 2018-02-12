#include <stdio.h>

#define MAX 1123

typedef long long ll;

ll max(ll a, ll b) { return a > b ? a : b; }

int main(void) {
  ll k, n, w, i, total;
  scanf("%lld %lld %lld", &k, &n, &w);
  for (total = 0, i = 1; i <= w; i++) total += k * i;
  printf("%lld\n", max(0, total - n));
  return 0;
}
