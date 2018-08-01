#include <stdio.h>

int main(void){
  int n, c, l, ans = 0;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &l, &c);
    if(l > c) ans += c;
  }
  printf("%d\n", ans);
  
  return 0;
}
