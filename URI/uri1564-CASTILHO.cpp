#include <stdio.h>

int main(void) {
  int n;
  while (scanf("%d", &n) != EOF)
    printf("vai ter %s!\n", n ? "duas" : "copa");
  return 0;
}
