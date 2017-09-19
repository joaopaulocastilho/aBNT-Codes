#include<stdio.h>

int main(void) {
  int n, a, b, j1, j2;
  while (scanf("%d", &n), n) {
    for (j1 = j2 = 0; n--; ) {
      scanf("%d %d", &a, &b);
      if (a > b) j1++;
      else if (a < b) j2++;
    }
    printf("%d %d\n", j1, j2);
  }
  return 0;
}
