#include <stdio.h>

int main(void) {
  int n, aM, am, i, resp, altura;
  while (scanf("%d %d %d", &n, &am, &aM) != EOF) {
    for (resp = i = 0; i < n; i++) {
      scanf("%d", &altura);
      if (altura >= am && altura <= aM) resp++;
    }
    printf("%d\n", resp);
  }
  return 0;
}
