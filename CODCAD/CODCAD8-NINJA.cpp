#include <stdio.h>

int main(void){
  int i, x;

  scanf("%d", &x);

  for(i = 1; i <= x; i++)
    if(x % i == 0) printf("%s%d", i > 1 ? " " : "", i);
  printf("\n");

  return 0;
}
