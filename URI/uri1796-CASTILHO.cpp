#include <stdio.h>

int main(void) {
  int q, i, s, qtd;
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &s);
    qtd += !s;
  }
  printf("%c\n", qtd > q / 2 ? 'Y' : 'N');
  return 0;
}
