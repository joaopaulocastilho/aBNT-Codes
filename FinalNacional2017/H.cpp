#include<stdio.h>

int main(void) {
  int c, b, p, cp, bp, pp, resp = 0;
  scanf("%d %d %d %d %d %d", &c, &b, &p, &cp, &bp, &pp);
  if (c < cp) resp = cp - c;
  if (b < bp) resp += bp - b;
  if (p < pp) resp += pp - p;
  printf("%d\n", resp);
  return 0;
}
