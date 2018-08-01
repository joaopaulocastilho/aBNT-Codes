#include <stdio.h>

int main(void){
  char c;
  double a, b;
  
  scanf("%c ", &c);
  scanf("%lf %lf\n", &a, &b);
  printf("%.2lf\n", c == 'M' ? a*b : a/b);

  return 0;
}
