#include <stdio.h>

int main(void) {
  int n, m1, m2, i1, i2, i, v;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v);
    if (v > m1) {
      m2 = m1; i2 = i1;
      m1 = v; i1 = i + 1;
    } else if (v > m2) {
      m2 = v;
      i2 = i + 1;
    }
  }
  printf("%d %d\n", i1, m2);
  return 0;
}
