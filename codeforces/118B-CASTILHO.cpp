#include <stdio.h>

int main(void) {
  int n, esp, i, j;
  scanf("%d", &n);
  for (i = 0, esp = n * 2; i <= n; i++, esp -= 2) {
    for (j = 0; j < esp; j++) printf(" ");
    for (j = 0; j <= i; j++) {
      if (j) printf(" ");
      printf("%d", j);
    }
    for (j = i - 1; j >= 0; j--) printf(" %d", j);
    printf("\n");
  }
  for (i = n - 1, esp = 2; i >= 0; i--, esp += 2) {
    for (j = 0; j < esp; j++) printf(" ");
    for (j = 0; j <= i; j++) {
      if (j) printf(" ");
      printf("%d", j);
    }
    for (j = i - 1; j >= 0; j--) printf(" %d", j);
    printf("\n");
  }
  return 0;
}
