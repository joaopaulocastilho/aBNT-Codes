#include <stdio.h>

int main(void) {
  int n, resp = 0, c, l;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &l, &c);
    if (l > c) resp += c;
  }
  printf("%d\n", resp);
  return 0;
}
