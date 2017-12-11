#include <stdio.h>

int main(void){
  int n, a, b, c, ans = 0;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d %d", &a, &b, &c);
    if(a + b + c >= 2) ans++;
  }
  printf("%d\n", ans);
  
  return 0;
}
