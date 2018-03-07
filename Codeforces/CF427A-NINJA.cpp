#include <stdio.h>

int main(void){
  int event, n, ans = 0, cops = 0;

  scanf("%d", &n);
  while(n--){
    scanf("%d", &event);
    if(event > 0) cops += event;
    else if(cops) cops--;
    else ans++;
  }

  printf("%d\n", ans);
  
  return 0;
}
