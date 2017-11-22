#include <stdio.h>

int main(void){
  int t, n, i, num, ans;

  scanf("%d", &t);
  for(i = 1; i <= t; i++){
    ans = -1;
    scanf("%d", &n);
    while(n--){
      scanf("%d", &num);
      if (num > ans) ans = num;
    }
    printf("Case %d: %d\n", i, ans);
  }

  return 0;
}
