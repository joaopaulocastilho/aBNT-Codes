#include<stdio.h>
#include<math.h>

int primo(int n) {
  int i, raiz;
  raiz = sqrt(n);
  for (i = 2; i <= raiz; i++)
    if (n % i == 0) return 0;
  return 1;
}

int main(void) {
  int n, flag = 1;
  scanf("%d", &n);
  while (flag && n) {
    if (primo(n)) { printf("%d\n", n); flag = 0; }
    n--;
  }
  return 0;
}
