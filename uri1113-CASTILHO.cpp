#include<stdio.h>

int main(void) {
  int a, b;
  while (scanf("%d %d", &a, &b), a != b)
    printf("%srescente\n", a > b ? "Dec" : "C");
  return 0;
}
