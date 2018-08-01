#include <stdio.h>

int main(void){
  int a, b, c, d;

  scanf("%d %d %d %d", &a, &b, &c, &d);
  a *= b; c *= d;
  printf("%s\n", a > c ? "Primeiro" : (c > a ? "Segundo" : "Empate"));

  return 0;
}
