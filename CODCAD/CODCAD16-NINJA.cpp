#include <stdio.h>

int main(void){
  int n, p, a, b, ans = 0;

  scanf("%d %d", &n, &p);
  while(n--){
    scanf("%d %d", &a, &b);
    if(a + b >= p) ans++;
  }
  printf("%d\n", ans);
  
  return 0;
}
