#include <stdio.h>

int main(void){
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  if(a == b || a == c || b == c || a + b == c || b + c == a || a + c == b) printf("S\n");
  else printf("N\n");

  return 0;
}
