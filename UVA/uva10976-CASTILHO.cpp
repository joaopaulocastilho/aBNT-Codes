#include <stdio.h>

#define MAX 11234
#define EPS 10e-9

struct resp_t { int x, y; resp_t() {}
  resp_t(int _x, int _y): x(_x), y(_y) {} };

int main(void) {
  int k, i, cont, flag;
  double xa;
  resp_t val[MAX];
  while (scanf("%d", &k) != EOF) {
    for (flag = 1, cont = 0, i = k + 1; flag; i++) {
      xa = ((double)k * i) / ((double)i - k);
      if (i > xa) { flag = 0; continue; }
      if (xa - (int)xa < EPS && i <= xa) val[cont++] = resp_t((int)xa, i);
    }
    printf("%d\n", cont);
    for (i = 0; i < cont; i++)
      printf("1/%d = 1/%d + 1/%d\n", k, val[i].x, val[i].y);
  }
  return 0;
}
