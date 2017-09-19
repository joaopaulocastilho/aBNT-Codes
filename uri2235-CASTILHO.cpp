#include<stdio.h>

int main(void) {
  int a, b, c, flag = 0;
  scanf("%d %d %d", &a, &b, &c);
  if (a == b || a == c || b == c || a == b + c || b == c + a ||
      c == a + b)
    flag = 1;
  printf("%c\n", flag ? 'S' : 'N');
  return 0;
}
