#include <stdio.h>

int main(void) {
  int t, pa, pb, resp;
  double g1, g2;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
    for (resp = 0; resp <= 100 && pa <= pb; resp++)
      { pa += (int)(pa * (g1 / 100)); pb += (int)(pb * (g2 / 100)); }
    if (resp <= 100) printf("%d anos.\n", resp);
    else printf("Mais de 1 seculo.\n");
  }
  return 0;
}
