#include <stdio.h>

typedef long long ll;

#define PRIMO 1000000007

int main(void) {
  int i, c, qh = 0, qm = 0, qtd = 0;
  ll resp;
  while ((c = getchar()) != '\n') {
    if (c == 'M') qh++;
    else qm++;
    if (qh == qm) qtd++;
  }
  for (resp = 1, i = 0; i < qtd - 1; i++)
    resp = (resp * 2) % PRIMO;
  printf("%lld\n", resp);
  return 0;
}
