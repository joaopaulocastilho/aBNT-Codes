#include <stdio.h>

typedef long long ll;

int main(void) {
  int x; ll n;
  while (scanf("%d %lld", &x, &n), x) printf("%lld\n", x * n);
  return 0;
}
