#include <stdio.h>
#include <math.h>

int eh_primo(int n) {
  int i, raiz = sqrt(n);
  if (n == 0 || n == 1) return 0;
  if (n == 2) return 1;
  for (i = 2; i <= raiz; i++)
    if (n % i == 0) return 0;
  return 1;
}

int main(void) {
  int n, super, d;
  while (scanf("%d", &n) != EOF) {
    if (eh_primo(n)) {
      for (super = 1; n; n /= 10) {
        d = n % 10;
        //printf("%d", d);
        super &= eh_primo(d);
      }
      //printf("\n");
      printf("%s\n", super ? "Super" : "Primo");
    } else {
      printf("Nada\n");
    }}
  return 0;
}
