#include <stdio.h>

int sum_digits(int n) {
  int ret = 0;
  while (n) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main(void) {
  int n, soma, resp = 0;
  scanf("%d", &n);
  for (resp = 1; n; resp++) {
    soma = sum_digits(n);
    n -= soma;
  }
  printf("%d\n", resp);
  return 0;
}
