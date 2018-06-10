#include <stdio.h>

int lun(int n) {
  int d;
  while (n) {
    d = n % 10;
    n /= 10;
    if (d != 4 && d != 7) return 0;
  }
  return 1;
}

int main(void) {
  int i, n, resp;
  scanf("%d", &n);
  for (resp = 0, i = 4; !resp && i <= n; i++)
    if (lun(i) && (n % i) == 0) resp = 1;
  printf("%s\n", resp ? "YES" : "NO");
  return 0;
}
