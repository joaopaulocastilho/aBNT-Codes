#include<stdio.h>

int main(void) {
  double sal, reajuste;
  int pct = 0;
  scanf("%lf", &sal);
  if (sal > 2000) pct = 4;
  else if (sal > 1200) pct = 7;
  else if (sal > 800) pct = 10;
  else if (sal > 400) pct = 12;
  else pct = 15;
  reajuste = sal*(pct/100.);
  printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %c\n",
	 sal+reajuste, reajuste, pct, '%');
  return 0;
}
