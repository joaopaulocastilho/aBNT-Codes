#include <stdio.h>
#include <math.h>

int ehprimo(int n) {
  int i, raiz = sqrt(n);
  for (i = 2; i <= raiz; i++)
    if (n % i == 0) return 0;
  return 1;
}

int main(void) {
  int n, x;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    printf("%d %seh primo\n", x, ehprimo(x) ? "" : "nao ");
  }
  return 0;
}
