#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  while (n--) printf("Ho%s", n ? " " : "!");
  printf("\n");
  return 0;
}
