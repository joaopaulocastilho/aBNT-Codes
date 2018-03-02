#include <cstdio>
#include <cmath>

int main(void){
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  printf("%.0lf\n",(int) ceil((a/c)) * ceil((b/c)));
  return 0;
}
