#include <stdio.h>

int main(void){
  int i, n, m, num, ans;

  while(scanf("%d %d", &n, &m ) != EOF){
    for(ans = i = 0; i < n; i++){
      scanf("%d", &num);
      if(i >= n-m) ans += num;
    }
    printf("%d\n", ans);
  }

  return 0;
}
