#include <stdio.h>

int main(void) {
  int t, r1, r2;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &r1, &r2);
    printf("%d\n", r1 + r2);
  }
  return 0;
}
