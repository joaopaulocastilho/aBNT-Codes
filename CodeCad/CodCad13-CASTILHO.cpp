#include <stdio.h>

#define BX 432
#define BY 468

int main(void) {
  int x, y, resp;
  scanf("%d %d", &x, &y);
  resp = (x >= 0 && x <= BX && y >= 0 && y <= BY);
  printf("%s\n", resp ? "dentro" : "fora");
  return 0;
}
