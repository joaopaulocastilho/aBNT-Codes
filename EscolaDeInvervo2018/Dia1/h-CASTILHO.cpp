#include <bits/stdc++.h>

int main(void) {
  int k, x, y, x1, y1;
  while (scanf("%d", &k), k) {
    scanf("%d %d", &x, &y);
    while (k--) {
      scanf("%d %d", &x1, &y1);
      if (x1 == x || y1 == y) printf("divisa\n");
      else if (x1 > x && y1 > y) printf("NE\n");
      else if (x1 < x && y1 > y) printf("NO\n");
      else if (x1 < x && y1 < y) printf("SO\n");
      else printf("SE\n");
    }
  }
  return 0;
}
