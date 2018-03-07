#include <stdio.h>
#include <string.h>

#define MAX 112345

int main(void){
  int cost[5], i, end, tmp, ans = 0;
  char str[MAX];

  for(i = 1; i <= 4; i++){
    scanf("%d", &tmp);
    cost[i] = tmp;
  }
  scanf(" %s", str);
  end = strlen(str);
  for(i = 0; i < end; i++){
    tmp = str[i] - '0';
    ans += cost[tmp];
  }
  printf("%d\n", ans);
  
  return 0;
}
