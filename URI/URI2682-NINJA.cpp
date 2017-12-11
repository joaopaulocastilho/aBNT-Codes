#include <stdio.h>

int main(void){
  int num, prev = 0, flag = 0;

  while(scanf("%d", &num) != EOF){
    if(num > prev && !flag) prev = num;
    else flag = 1;
  }
  printf("%d\n", prev + 1);

  return 0;
}
