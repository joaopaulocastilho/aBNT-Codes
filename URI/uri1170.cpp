#include<stdio.h>

#define EPS 10e-9

int main(void) {
  int t, resp; double n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf", &n);
    for (resp = 0; n - 1 >= EPS; resp++) { n /= 2; }
    printf("%d dias\n", resp);
  }
  return 0;
}
