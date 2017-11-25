#include <stdio.h>

int main(void) {
  int n, x = 0;
  char c1, c2, c3;
  scanf("%d", &n);
  while (n--) {
    scanf(" %c %c %c", &c1, &c2, &c3);
    if (c2 == '+') x++;
    else x--;
  }
  printf("%d\n", x);
  return 0;
}
