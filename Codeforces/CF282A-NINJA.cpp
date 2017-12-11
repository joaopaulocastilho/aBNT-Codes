#include <stdio.h>

#define MAX 11

int main(void){
  int n, ans = 0;
  char str[MAX];

  scanf("%d ", &n);
  while(n--){
    scanf("%s ", str);
    if(str[0] == '+' || str[2] == '+') ans++;
    else ans--;
  }
  printf("%d\n", ans);
  
  return 0;
}
