#include <stdio.h>

#define pos(x, y) ((x) >= 0 && (y) >= 0)

int main(void) {
  int n, s, d, x, y;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &s, &d);
    y = (s - d) / 2;
    x = s - y;
    if (pos(x, y) && x + y == s && x - y == d) printf("%d %d\n", x, y);
    else printf("impossible\n");
  }
  return 0;
}
