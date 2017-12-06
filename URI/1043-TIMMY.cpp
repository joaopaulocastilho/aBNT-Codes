#include <cstdio>

int main(void){
  double a, b, c;

  scanf("%lf %lf %lf", &a, &b, &c);
  if(a + b > c && a + c > b && b + c > a) printf("Perimetro = %.1lf\n", a + b + c);
  else printf("Area = %.1lf\n", ((a * c)/2 + (b * c)/2));
  return 0;
}
