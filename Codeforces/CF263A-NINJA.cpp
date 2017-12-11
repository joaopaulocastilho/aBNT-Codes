#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i, j, ia, ja, num;

  for(i = 1; i <= 5; i++)
    for(j = 1; j <= 5; j++){
      scanf("%d", &num);
      if(num) { ia = i; ja = j; }
    }
  printf("%d\n", abs(3 - ia) + abs(3 - ja));
  
  return 0;
}
