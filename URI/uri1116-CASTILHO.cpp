#include<stdio.h>

int main(void) {
  int n;
  double a, b;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf", &a, &b);
    if (b) printf("%.1lf\n", a / b);
    else printf("divisao impossivel\n");
  }
  return 0;
}
