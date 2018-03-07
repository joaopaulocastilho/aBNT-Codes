#include <stdio.h>

int main(void){
  int i, n, add, ans = 0;

  scanf("%d", &n);
  for(add = 0, i = 1; ; i++, ans++){
    add += i;
    if(n < add) break;
    n -= add;
  }
  printf("%d\n", ans);
  
  return 0;
}
