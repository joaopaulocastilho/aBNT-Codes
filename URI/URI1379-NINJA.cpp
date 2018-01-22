#include <stdio.h>

int main(void){
  int a, b;

  while(scanf("%d %d", &a, &b), a || b){
    printf("%d\n", 3*a - a - b);
  }

  return 0;
}
