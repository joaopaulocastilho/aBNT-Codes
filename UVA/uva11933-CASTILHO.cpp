#include <stdio.h>

int main(void) {
  int n, i, pa, a, b;
  while (scanf("%d", &n), n) {
    a = b = 0;
    for (pa = 1, i = 0; n; i++) {
      if (n & (1 << i)) {
        if (pa) a |= 1 << i;
        else b |= 1 << i;
        n ^= 1 << i; pa = !pa;
      }}
    printf("%d %d\n", a, b);
  }
  return 0;
}
