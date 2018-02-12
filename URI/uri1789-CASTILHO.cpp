#include <stdio.h>

int main(void) {
  int l, i, v, maior;
  while (scanf("%d", &l) != EOF) {
    for (maior = i = 0; i < l; i++) {
      scanf("%d", &v);
      if (v > maior) maior = v;
    }
    if (maior >= 20) printf("3\n");
    else if (maior >= 10) printf("2\n");
    else printf("1\n");
  }
  return 0;
}
