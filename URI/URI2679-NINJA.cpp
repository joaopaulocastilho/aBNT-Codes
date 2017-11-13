#include <stdio.h>

int main(void){
  int a;

  scanf("%d", &a);
  printf("%d\n", a % 2 ? a + 1 : a + 2);
}
