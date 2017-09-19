#include<stdio.h>

int main(void) {
  int l, r;
  while (scanf("%d %d", &l, &r), l != 0 || r != 0) {
    printf("%d\n", l + r);
  }
  return 0;
}
