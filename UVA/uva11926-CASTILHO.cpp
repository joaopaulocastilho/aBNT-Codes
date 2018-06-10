#include <stdio.h>
#include <string.h>

#define MAX 1123456

int ok(int min[], int inf, int sup) {
  int i;
  for (i = inf; i <= 1000000 && i < sup; i++) if (min[i]) return 0;
  return 1;
}

int main(void) {
  int n, m, i, resp, inf, sup, rep, mul, infa, supa, min[MAX];
  while (scanf("%d %d", &n, &m), n || m) {
    memset(min, 0, sizeof(min)); resp = 1;
    while (n--) {
      scanf("%d %d", &inf, &sup);
      if (!resp) continue;
      resp &= ok(min, inf, sup);
      for (i = inf; resp && i < sup; i++) min[i] = 1;
    }
    while (m--) {
      scanf("%d %d %d", &inf, &sup, &rep);
      if (!resp) continue;
      for (mul = 0; (mul * rep) + inf <= 1000000; mul++) {
        infa = (mul * rep) + inf; supa = (mul * rep) + sup;
        resp &= ok(min, infa, supa);
        for (i = infa; resp && i <= 1000000 && i < supa; i++)
          min[i] = 1;
      }}
    printf("%sCONFLICT\n", resp ? "NO " : "");
  }
  return 0;
}
