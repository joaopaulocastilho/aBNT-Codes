#include <stdio.h>

int main(void){
  int c1, c2, p1, p2, ans;

  scanf("%d %d %d %d", &p1, &c1, &p2, &c2);
  
  if(p1*c1 > p2*c2) ans = -1;
  else if(p1*c1 < p2*c2) ans = 1;
  else ans = 0;

  printf("%d\n", ans);
  
  return 0;
}
