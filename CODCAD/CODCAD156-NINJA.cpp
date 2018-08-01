#include <stdio.h>

int main(void){
  int n, time, t, i, ans;
  
  scanf("%d", &n);
  for(ans = i = time = 0; i < n; i++){
    scanf("%d", &t);
    if(t >= time) ans += 10;
    else ans += (t+10)-time;
    time = t + 10;
  }
  printf("%d\n", ans);
  return 0;
}
