#include<stdio.h>

#define valida(a, b ,c) (a) + (b) > (c)

int main(void) {
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  if (valida(a, b, c) && valida(a, c, b) && valida(b, c, a))
    printf("Perimetro = %.1lf\n", a+b+c);
  else printf("Area = %.1lf\n", c * ((a + b) / 2));  
  return 0;
}
