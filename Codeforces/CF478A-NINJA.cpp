#include <stdio.h>

int main(void){
  int i, x, sum;

  for(sum = i = 0; i < 5; i++){
    scanf("%d", &x);
    sum += x;
  } 
  printf("%d\n", (sum % 5 || sum < 5) ? -1 : sum/5);

  return 0;
}
