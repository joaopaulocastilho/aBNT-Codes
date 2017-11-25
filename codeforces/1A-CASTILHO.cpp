#include<stdio.h>
#include<math.h>

int main(void) {
  long long n, m, a;
  scanf("%lld %lld %lld", &n, &m, &a);
  printf("%lld\n", (long long)(ceil((double)n / a) * ceil( (double)m / a)));
  return 0;
}
