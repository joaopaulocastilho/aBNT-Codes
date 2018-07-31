#include <stdio.h>

int main(void) {
  int l, c, resp = 1;
  scanf("%d %d", &l, &c);
  resp = (l & 1);
  if (resp) resp = (c & 1);
  else resp = !(c & 1);
  printf("%d\n", resp);
  return 0;
}
