#include <stdio.h>

int main(void){
  int n, i, last, ans, curr;

  scanf("%d", &n);
  scanf("%d", &last);
  for(ans = i = 1; i < n; i++){
    scanf("%d", &curr);
    if(curr != last) {ans++; last = curr;}
  }
  printf("%d\n", ans);
  
  return 0;
}
