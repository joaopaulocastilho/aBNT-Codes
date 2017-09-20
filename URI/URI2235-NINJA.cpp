#include <stdio.h>

int main(void){
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  if(a == b || a == c || b == c) printf("S\n");
  else if(a + b == c || a + c == b || b + c == a) printf("S\n");
  else printf("N\n");

  return 0;
}
