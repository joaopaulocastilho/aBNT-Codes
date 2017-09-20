#include <stdio.h>

int main(void){
  int a, b, c;
  scanf("%d %d", &a, &b);
  while(a != 0 && b != 0){
    c = a + b;
    printf("%d\n", c);
    scanf("%d %d", &a, &b);
  }
  return 0;
}
