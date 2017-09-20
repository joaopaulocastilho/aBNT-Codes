#include<stdio.h>

#define EPS 10e-9

int main(void) {
  int i;
  double n;
  for (i = 0; i < 100; i++) {
    scanf("%lf", &n);
    if (n - 10 <= EPS) printf("A[%d] = %.1lf\n", i, n);
  }
  return 0;
}
