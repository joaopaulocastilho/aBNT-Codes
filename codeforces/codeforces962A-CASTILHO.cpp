#include <stdio.h>
#include <math.h>

#define MAX 212345

int main(void) {
  int n, i, p[MAX], total = 0, ac = 0, aux;
  scanf("%d", &n);
  for (i = 0; i < n; i++) { scanf("%d", &p[i]); total += p[i]; }
  for (i = 0, aux = ceil((double)total / 2.); i < n; i++) {
    ac += p[i];
    if (ac >= aux) break;
  }
  printf("%d\n", i + 1);
  return 0;
}
