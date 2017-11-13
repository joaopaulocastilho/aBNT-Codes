#include <stdio.h>

int main(void){
  int n, x, amin, amax, ans;

  while(scanf("%d %d %d", &n, &amin, &amax) != EOF){
    for(ans = 0; n; n--){
      scanf("%d", &x);
      if(x >= amin && x <= amax) ans++;
    }
    printf("%d\n", ans);
  }

  return 0;
}
