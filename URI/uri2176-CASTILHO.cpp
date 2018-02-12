#include <stdio.h>

int main(void) {
  char c; int par = 0;
  while ((c = getchar()) != EOF) {
    printf("%c", c);
    if (c == '1') par = !par;
  }
  printf("%d\n", par);
  return 0;
}
