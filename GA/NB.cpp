#include <stdio.h>
#include <math.h>

int main(void) {
  int g1, g2, p1, p2, v1, v2;
  scanf("%d %d %d %d", &g1, &p1, &g2, &p2);
  p2++;
  v1 = ceil(((double)g1 * p1) / 100.);
  v2 = floor(((double)g2 * p2) / 100.);
  if ((g2 * p2) % 100 == 0) v2--;
  printf("%d\n", v2 - v1);
  return 0;
}
