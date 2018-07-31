#include <stdio.h>

int main(void) {
  int n, resp, i;
  scanf("%d", &n);
  for (resp = i = 1; i <= n; i++) resp *= i;
  printf("%d\n", resp);
  return 0;
}
