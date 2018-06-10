#include <stdio.h>

int main(void) {
  int i, d1, d2, k;
  scanf("%d %d %d", &d1, &d2, &k);
  for (i = 0; i < k; i++)
    if (d1 > d2) d2++;
    else d1++;
  printf("%.6lf\n", ((double)d1 * d2) / 2.);
  return 0;
}
