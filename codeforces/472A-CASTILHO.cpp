#include <stdio.h>
#include <math.h>

int primo(int n) {
  int i, raiz = sqrt(n), primo = 1;
  for (i = 2; primo && i <= raiz; i++)
    if (n % i == 0) primo = 0;
  return primo;
}

int main(void) {
  int n, a, b;
  scanf("%d", &n);
  if (n & 1) { a = n / 2; b = n / 2 + 1; }
  else { a = b = n / 2; }
  while (primo(a) || primo(b)) { a--; b++; }
  printf("%d %d\n", a, b);
  return 0;
}
