#include <stdio.h>

int main(void){
  double a, b;

  scanf("%lf %lf", &a, &b);
  printf("%s\n", a <= b ? "Pedro" : "Paulo");
  
  return 0;
}
