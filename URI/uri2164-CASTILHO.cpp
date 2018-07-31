#include <stdio.h>
#include <math.h>

double exp(double a, int b) {
  if (!b) return 1;
  return a * exp(a, b - 1);
}

double fib(int n) {
  double t1 = ((1 + sqrt(5)) / 2), t2 =  ((1 - sqrt(5)) / 2);
  t1 = exp(t1, n); t2 = exp(t2, n);
  return (t1 - t2) / sqrt(5);
}

int main(void) {
  int n;
  scanf("%d", &n);
  printf("%.1lf\n", fib(n));
  return 0;
}
