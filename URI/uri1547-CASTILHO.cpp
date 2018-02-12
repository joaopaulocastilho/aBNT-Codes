#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, qt, i, s, atual, dist, resp;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &qt, &s);
    for (dist = 1123456789, i = 1; i <= qt; i++) {
      scanf("%d", &atual);
      if (dist > abs(atual - s)) {
        dist = abs(atual - s); resp = i;
      }
    }
    printf("%d\n", resp);
  }
  return 0;
}
