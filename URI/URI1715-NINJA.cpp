#include <stdio.h>

int main(void){
  int i, n, g, flag, goal, ans = 0;

  scanf("%d %d", &n, &g);
  while(n--){
    for(flag = 1, i = 0; i < g; i++){
      scanf("%d", &goal);
      if(goal == 0) flag = 0;
    }
    if(flag) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
