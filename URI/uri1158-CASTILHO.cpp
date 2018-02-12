#include <stdio.h>

int main(void) {
  int x, y, n, i, j, resp;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &x, &y);
    for (resp = j = 0, i = x; j < y; i++) {
      if (i & 1) {
        resp += i;
        j++;
      }
    }
    printf("%d\n", resp);
  }
  return 0;
}
