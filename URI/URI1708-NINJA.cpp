#include <stdio.h>

int main(void){
  int a, b, i, x, y;

  scanf("%d %d", &a, &b);
  for(x = y = 0, i = 1; y-x < a; i++, x += a, y += b);
  printf("%d\n", i);
  return 0;
}
