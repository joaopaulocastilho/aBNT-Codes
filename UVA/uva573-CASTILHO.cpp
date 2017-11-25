#include <stdio.h>

#define EPS 10e-9

int main(void) {
  int h, u, d, f, i, flag, resp;
  double curH, desloc;
  while (scanf("%d %d %d %d", &h, &u, &d, &f), h) {
    desloc = u;
    for (resp = curH = 0, flag = i = 1; flag; i++) {
      if (desloc > EPS) curH += desloc;
      if (desloc > EPS && curH - h >= EPS) { resp = i; break; }
      curH -= d;
      if (curH < 0) { resp = i; flag = 0; }
      if (desloc < 0) desloc += u * ((double)f / 100);
      else desloc -= u * ((double)f / 100);
      //printf("Dia: %d, Cur: %.3lf, Desloc: %.3lf\n", i, curH, desloc);
    }
    printf("%s on day %d\n", flag ? "success" : "failure", resp);
    //printf("\n");
  }
  return 0;
}
