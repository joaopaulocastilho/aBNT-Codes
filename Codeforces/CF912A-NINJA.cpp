#include <stdio.h>

int main(void){
  long long int yc, bc, yb, gb, bb, buyy, buyb, ans = 0;

  scanf("%lld %lld", &yc, &bc);
  scanf("%lld %lld %lld", &yb, &gb, &bb);
  buyy = 2 * yb + gb - yc;
  buyb = 3 * bb + gb - bc;
  if(buyy > 0) ans += buyy;
  if(buyb > 0) ans += buyb;
  printf("%lld\n", ans);
  
  return 0;
}
