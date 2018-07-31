#include <stdio.h>

int main(void) {
  int n, resp;
  scanf("%d", &n);
  resp = n / 100;
  n = n % 100;
  resp += n / 20;
  n = n % 20;
  resp += n / 10;
  n = n % 10;
  resp += n / 5;
  n = n % 5;
  resp += n;
  printf("%d\n", resp);
  return 0;
}
