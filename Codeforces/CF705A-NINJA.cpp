#include <stdio.h>

int main(void){
  int n, flag = 1;
  
  scanf("%d", &n);
  for(; n; n--){
    printf("%s%s", flag ? "I hate " : "I love ", n == 1 ? "it" : "that ");
    flag = flag ? 0 : 1;	  
  }
  printf("\n");
  return 0;
}