#include <stdio.h>

int main(void) {
  int x, y, i, pula, first, fbn;
  scanf("%d %d", &x, &y);
  for (first = pula = i = 1; i <= y; i++, pula++) {
    if (first) first = 0;
    else printf(" ");
    printf("%d", i);
    fbn = 1;
    if (i % x == 0) { printf("\n"); first = 1; fbn = 0; }
  }
  if (fbn) printf("\n");
  return 0;
}
