#include <stdio.h>

typedef long long ll;

int main(void) {
  ll a, b, resp = 0;
  scanf("%lld %lld", &a, &b);
  resp =  (a + b) * (b - a + 1) / 2;
  printf("%lld\n", resp);
  return 0;
}
