#include <stdio.h>

int main(void) {
  int v1, v2, t1 = 0, t2 = 0, lap;
  scanf("%d %d", &v1, &v2); t1 = v1; t2 = v2;
  for (lap = 1; ; ) {
    lap++;
    if (t1 + v1 <= t2) break;
    t1 += v1; t2 += v2;
  }
  printf("%d\n", lap);
  return 0;
}
