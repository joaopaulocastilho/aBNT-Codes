#include <stdio.h>

int main(void) {
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", (n * (n - 3)) / 2);
  return 0;
}
