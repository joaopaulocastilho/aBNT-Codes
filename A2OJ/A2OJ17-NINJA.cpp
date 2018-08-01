#include <stdio.h>

#define MAX 112

int main(void){
  int t, n, k, ans, num;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    for(ans = 0; n; n--){
      scanf("%d", &num);
      ans += num / k;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
