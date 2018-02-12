#include <stdio.h>

int main(void) {
  int n, atual, resp, sinal, i;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &atual);
    for (resp = i = 1, sinal = 0; i < atual; i++) {
      if (sinal) resp += 1;
      else resp -= 1;
      sinal = !sinal;
    }
    printf("%d\n", resp);
  }
  return 0;
}
