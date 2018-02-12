#include <stdio.h>

int main(void) {
  int v, n, resp = 0;
  scanf("%d", &v);
  while (scanf("%d", &n), n <= 0);
  while (n--) { resp += v; v++; }
  printf("%d\n", resp);
  return 0;
}
