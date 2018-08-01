#include <stdio.h>

int main(void){
  double a, b, m;

  scanf("%lf %lf", &a, &b);
  m = (a+b)/2;
  if(m >= 7) printf("Aprovado\n");
  else if(m >= 4) printf("Recuperacao\n");
  else printf("Reprovado\n");
  
  return 0;
}
