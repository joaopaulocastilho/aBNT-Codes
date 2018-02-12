#include <stdio.h>

int main(void) {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  printf("%s\n", (a + b <= n) ? "Farei hoje!" : "Deixa para amanha!");
  return 0;
}
