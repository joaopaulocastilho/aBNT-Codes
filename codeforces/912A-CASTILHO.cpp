#include <stdio.h>

typedef long long ll;

ll max(ll a, ll b) {
  if (a > b) return a;
  return b;
}

int main(void) {
  int a, b, x, y, z;
  ll qty, qtb, resp;
  scanf("%d %d %d %d %d", &a, &b, &x, &y, &z);
  qty = (ll)x * 2 + y;
  qtb = (ll)z * 3 + y;
  resp = max(0, qty - a);
  resp += max(0, qtb - b);
  printf("%lld\n", resp);
  return 0;
}
