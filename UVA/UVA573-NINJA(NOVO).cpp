#include <stdio.h>

int main(void){
  double h, u, d, f, pos;
  int ans;
  
  while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f), h){
    for(f = u * (f/100), pos = 0, ans = 1; ; ans++){
      if(u > 0) pos += u;
      //printf("%lf %lf\n", pos, u);
      if(pos > h) { printf("success on day %d\n", ans); break; }
      u -= f; pos -= d;
      if(pos < 0) { printf("failure on day %d\n", ans); break; }
    }
  }
  return 0;
}
