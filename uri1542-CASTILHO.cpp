#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int mdc(int a, int b) { return a * (b / gcd(a, b)); }

int main(void) {
  int pl, a, p, tmp, paginas, flag, t1, t2;
  while (scanf("%d", &pl), pl) {
    scanf("%d %d", &a, &p);
    tmp = mdc(pl, p);
    flag = 1; paginas = tmp;
    while (flag) {
      t1 = paginas / pl;
      t2 = paginas / p;
      if (abs(t1 - t2) == a) flag = 0;
      else paginas += tmp;
    }
    printf("%d paginas\n", paginas);
  }
  return 0;
}
