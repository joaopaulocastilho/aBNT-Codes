#include <stdio.h>

int main(void) {
  int t, v;
  while (scanf("%d %d", &t, &v) != EOF)
    printf("%d\n", t * v * 2);
  return 0;
}
