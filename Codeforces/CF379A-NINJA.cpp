#include <stdio.h>

int main(void){
  int a, b, i;

  scanf("%d %d", &a, &b);

  for(i = 1; i <= a; i++)
    if(i % b == 0) a++;
  printf("%d\n", i-1);
  
  return 0;
}
