#include<stdio.h>

int main(void) {
  int q, d, p, resp;
  while (scanf("%d", &q), q) {
    scanf("%d %d", &d, &p);
    resp = (((double)q * d) / (p - q)) * p;
    printf("%d pagina%s\n", resp, resp == 1 ? "" : "s");
  }
  return 0;
}
