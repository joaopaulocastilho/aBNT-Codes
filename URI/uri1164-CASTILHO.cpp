#include <stdio.h>

int main(void) {
  int n, x, i;
  long long soma;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    for (soma = 0, i = 1; i < x; i++) {
      if (x % i == 0) soma += i;
    }
    printf("%d %seh perfeito\n", x, soma == x ? "" : "nao ");
  }
  return 0;
}
