#include <stdio.h>

int main(void){
  int n, num, sum = 0, i;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &num);
    sum += num;
    if (sum >= 1000000) break;
  }
  printf("%d\n", i);
  
  return 0;
}
