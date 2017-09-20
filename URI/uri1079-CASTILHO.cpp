#include<stdio.h>

int main(void) {
  int n;
  double n1, n2, n3;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf", &n1, &n2, &n3);
    printf("%.1lf\n", n1 * 0.2 + n2 * 0.3 + n3 * 0.5);
  }
  return 0;
}
