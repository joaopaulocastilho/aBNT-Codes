#include<stdio.h>

int main(void) {
  int n, size, qtt, resp;
  while (scanf("%d", &n), n) {
    for (resp = 0; n--; ) {
      scanf("%d %d", &size, &qtt);
      resp += (qtt & 1) ? qtt - 1 : qtt;
    }
    printf("%d\n", resp / 4);
  }
  return 0;
}
