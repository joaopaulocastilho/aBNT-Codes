#include <stdio.h>

int main(void) {
  int v, i;
  for (i = 1; i <= 4; i++) {
    scanf("%d", &v);
    if (v) printf("%d\n", i);
  }
  return 0;
}
