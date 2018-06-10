#include <stdio.h>
#include <string.h>

int main(void) {
  int n, x, y, resp[4];
  scanf("%d", &n);
  memset(resp, 0, sizeof(resp));
  while (n--) {
    scanf("%d %d", &x, &y);
    if (x > 0 && y > 0) resp[0] = 1;
    else if (x < 0 && y > 0) resp[1] = 1;
    else if (x > 0 && y < 0) resp[2] = 1;
    else if (x < 0 && y < 0) resp[3] = 1;
  }
  printf("%d\n", resp[0] + resp[1] + resp[2] + resp[3]);
  return 0;
}
