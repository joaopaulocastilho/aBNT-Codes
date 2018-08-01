#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int num, i, ans, n, m, flag;

  scanf("%d %d", &n ,&m);
  ans = 0;
  while(n--){
    for(flag = 1, i = 0; i < m; i++){
      scanf("%d", &num);
      if(num < 1) flag = 0;
    }
    if(flag) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
