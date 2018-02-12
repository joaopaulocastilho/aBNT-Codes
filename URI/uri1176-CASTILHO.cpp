#include <stdio.h>

int main(void) {
  int n, i, caso;
  long long fib[112];
  fib[0] = 0; fib[1] = 1;
  for (i = 2; i <= 60; i++)
    fib[i] = fib[i - 1] + fib[i - 2];
  scanf("%d", &caso);
  while (caso--) {
    scanf("%d", &n);
    printf("Fib(%d) = %lld\n", n, fib[n]);
  }
  return 0;
}
