#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int tamanho(int n) {
  int ret;
  for (ret = 0; n; n /= 10, ret++);
  return ret;
}

int main(void) {
  int n, i, tmp, soma, caso, pi, num, den, neg;
  for (caso = 1; scanf("%d", &n), n; caso++) {
    printf("Case %d:\n", caso);
    for (soma = i = 0; i < n; i++) {
      scanf("%d", &tmp);
      soma += tmp;
    }
    neg = soma < 0;
    if (abs(soma) % n == 0)
      { printf("%s%d\n", neg ? "- " : "", abs(soma / n)); continue; }
    for (pi = abs(soma / n), tmp = abs(soma); tmp % n; tmp--);
    num =  (abs(soma) - tmp) / gcd(abs(soma) - tmp, n);
    den = n / gcd(abs(soma) - tmp, n);
    if (pi == 0) {
      if (neg) printf("  ");
      for (i = 0; i < tamanho(den) - tamanho(num); i++) printf(" ");
      printf("%d\n", num);
      if (neg) printf("- ");
      for (i = 0; i < tamanho(den); i++) printf("-");
      printf("\n");
      if (neg) printf("  ");
      printf("%d\n", den);
      continue;
    }
    if (neg) printf("  ");
    for (i = 0; i < tamanho(den) - tamanho(num); i++) printf(" ");
    for (i = 0; i < tamanho(pi); i++) printf(" ");
    printf("%d\n", num);
    if (neg) printf("- ");
    printf("%d", pi);
    for (i = 0; i < tamanho(den); i++) printf("-");
    printf("\n");
    if (neg) printf("  ");
    for (i = 0; i < tamanho(pi); i++) printf(" ");
    printf("%d\n", den);
  }
  return 0;
}
