#include <stdio.h>

typedef long long ll;

int main(void) {
  int i, n, flag = 1, antb = 2, mudac = 0;
  ll a = 1, b = 1, c = 1, m1, m2;
  scanf("%d", &n);
  for (i = 0; i < n * 2; i++, flag = !flag) {
    printf("%lld ", a);
    m1 = a;
    if (!flag) a++;
    printf("%lld ", b);
    m2 = b;
    if (flag) b++;
    else { b += antb; antb += 2; }
    if (mudac) { c = m1 * m2; mudac = 0; }
    printf("%lld\n", c);
    if (flag) c++;
    else mudac = 1;
  }
  return 0;
}
