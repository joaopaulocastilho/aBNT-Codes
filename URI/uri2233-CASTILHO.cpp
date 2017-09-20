#include<stdio.h>

typedef long long ll;

int main(void) {
  ll r, g, b, qg, qb;
  scanf("%llx %llx %llx", &r, &g, &b);
  qg = (r / g) * (r / g);
  qb = (g / b) * (g / b) * qg;
  printf("%llx\n", 1 + qg + qb);
  return 0;
}
