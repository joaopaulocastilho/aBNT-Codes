#include <stdio.h>

int main(void){
  int l, c;

  scanf("%d %d", &l, &c);
  printf("%d\n%d\n", c*l + (c-1)*(l-1), 2*(c-1) + 2*(l-1));

  return 0;
}
