#include <stdio.h>

int main(void) {
  double A, G, ra, rg;
  scanf("%lf %lf %lf %lf", &A, &G, &ra, &rg);
  if (ra / A > rg / G) printf("A\n");
  else printf("G\n");
  return 0;
}
