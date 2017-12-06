#include <cstdio>

int main(void){
  double h, u, d, day;
  double frequency, f, ans;
  while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f), h != 0){
    ans = 0;
    day = 0;
    while(1){
      day++;
      frequency = u * (f/100) * (day-1);
      if(u - frequency > 0){
	ans += u;
	if(day != 1) ans -= frequency;
      }
      if(ans > h)
	break;
      ans -= d;
      if(ans < 0) break;
    }
    if(ans > h) printf("success on day %.0lf\n", day);
    if(ans < 0) printf("failure on day %.0lf\n", day);
  }
  return 0;
}
