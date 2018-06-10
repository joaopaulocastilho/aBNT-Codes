#include <stdio.h>

int main(void) {
  int i, soma, x, y, resp;
  scanf("%d", &x);
  while (scanf("%d", &y), y <= x);
  for (resp = 1, i = x + 1, soma = x; soma < y; i++, resp++) soma += i;
  printf("%d\n", resp);
  return 0;
}
