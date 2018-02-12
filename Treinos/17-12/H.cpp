#include <stdio.h>

int forca[] = { 0, 11, 20, 30, 1, 2, 3, 4, 5, 6, 7, 9, 8, 10 };

int vence(int b, int a) {
  if (forca[b] > forca[a]) return 1;
  return 0;
}

int main(void) {
  int adal = 0, bern = 0, n, a1, a2, a3, b1, b2, b3, ra, rb;
  scanf("%d", &n);
  while (n--) {
    ra = rb = 0;
    scanf("%d %d %d", &a1, &a2, &a3);
    scanf("%d %d %d", &b1, &b2, &b3);
    if (vence(b1, a1)) rb++;
    else ra++;
    if (vence(b2, a2)) rb++;
    else ra++;
    if (vence(b3, a3)) rb++;
    else ra++;
    if (ra > rb) adal++;
    else bern++;
  }
  printf("%d %d\n", adal, bern);
  return 0;
}
