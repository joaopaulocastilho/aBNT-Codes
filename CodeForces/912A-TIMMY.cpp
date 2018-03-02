#include <cstdio>

int main(void){
  long int cury, curb, yellow, green, blue;
  scanf("%ld %ld", &cury, &curb);
  scanf("%ld %ld %ld", &yellow, &green, &blue);
  long int requiredy = (yellow * 2 + green) - cury;
  long int requiredb = (blue * 3 + green) - curb;
  long int ans = 0;
  if(requiredy > 0) ans += requiredy;
  if(requiredb > 0) ans += requiredb;
  printf("%ld\n", ans);
  return 0;
}
