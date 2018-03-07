#include <stdio.h>

int main(void){
  int x, ans = 0;

  scanf("%d", &x);
  ans += x / 5; x = x % 5;
  ans += x / 4; x = x % 4;
  ans += x / 3; x = x % 3;
  ans += x / 2; x = x % 2;
  ans += x / 1; x = x % 1;

  printf("%d\n", ans);
  
  return 0;
}
