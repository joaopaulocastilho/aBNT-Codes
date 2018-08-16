#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull solve(ull n) {
  ull p, pint, resto, ret = 0;
  for (p = 1; p <= n; p *= 2) {
    pint = n / (2 * p);
    resto = n % (2 * p);
    ret += pint * p;
    if (resto > p) ret += resto - p;
  }
  return ret;
}

int main(void) {
  ull a, b;
  while (scanf("%llu %llu", &a, &b) != EOF) printf("%llu\n", solve(b + 1) - solve(a));
  return 0;
}
