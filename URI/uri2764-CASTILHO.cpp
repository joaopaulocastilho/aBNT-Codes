#include <stdio.h>

int main(void) {
  int d, m, a;
  scanf("%d/%d/%d", &d, &m, &a);
  printf("%.2d/%.2d/%.2d\n", m, d, a);
  printf("%.2d/%.2d/%.2d\n", a, m, d);
  printf("%.2d-%.2d-%.2d\n", d, m, a);
  return 0;
}
