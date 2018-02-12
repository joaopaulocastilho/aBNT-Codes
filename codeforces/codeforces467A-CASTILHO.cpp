#include <stdio.h>

int main(void) {
  int n, pi, qi, resp = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &pi, &qi);
    if (qi - pi >= 2) resp++;
  }
  printf("%d\n", resp);
  return 0;
}
