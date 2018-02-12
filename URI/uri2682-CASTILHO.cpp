#include <stdio.h>

int main(void) {
  int n, ant = -1, flag = 1;
  while (scanf("%d", &n) != EOF) {
    if (n < ant && flag) {
      printf("%d\n", ant + 1);
      flag = 0;
    }
    ant = n;
  }
  if (flag) printf("%d\n", n + 1);
  return 0;
}
