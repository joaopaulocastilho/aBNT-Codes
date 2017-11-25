#include <stdio.h>

#define MAX 112
#define EPS 10e-9

int main(void) {
  int mo, nr, resp, new_m, i;
  double dp, al, car, new_p, parc[MAX], ower, ppm;
  while (scanf("%d %lf %lf %d", &mo, &dp, &al, &nr), mo > 0) {
    while (nr--) {
      scanf("%d %lf", &new_m, &new_p);
      for (i = new_m; i < MAX; i++)
        parc[i] = new_p;
    }
    resp = 0; car = al + dp; car -= (car * parc[0]);
    ppm = al / mo; ower = al;
    while (ower - car > EPS) {
      resp++;
      car -= (car * parc[resp]);
      ower -= ppm;
    }
    printf("%d month%s\n", resp, (resp != 1) ? "s" : "");
  }
  return 0;
}
