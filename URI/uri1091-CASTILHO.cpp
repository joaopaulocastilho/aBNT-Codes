#include<stdio.h>

int main(void) {
  int k, x_div, y_div, x, y;
  while (scanf("%d", &k), k) {
    scanf("%d %d\n", &x_div, &y_div);
    while (k--) {
      scanf("%d %d", &x, &y);
      if (x_div == x || y_div == y) printf("divisa\n");
      else if (x > x_div && y > y_div) printf("NE\n");
      else if (x > x_div && y < y_div) printf("SE\n");
      else if (x < x_div && y > y_div) printf("NO\n");
      else printf("SO\n");
    }}
  return 0;
}
