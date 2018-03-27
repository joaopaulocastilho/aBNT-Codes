#include <stdio.h>

int main(void) {
  int casos, a, b, c, flag, x, y, z;
  scanf("%d", &casos);
  while (casos--) {
    scanf("%d %d %d", &a, &b, &c);
    for (flag = 0, x = -100; !flag && x <= 100; x++)
      for (y = x + 1; !flag && y <= 100; y++)
	for (z = y + 1; !flag && z <= 100; z++) {
	  if (x + y + z == a && x * y * z == b &&
	      x * x + y * y + z * z == c) {
	    flag = 1;
	    printf("%d %d %d\n", x, y, z);
	    break; }
	}
    if (!flag) printf("No solution.\n");
  }
  return 0;
}
