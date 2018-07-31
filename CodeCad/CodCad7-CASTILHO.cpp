#include <stdio.h>

int main(void) {
  int ao, ap, ab, bo, bp, bb, resp = -1;
  scanf("%d %d %d %d %d %d", &ao, &ap, &ab, &bo, &bp, &bb);
  if (ao > bo) resp = 1;
  else if (bo > ao) resp = 2;
  if (resp == -1 && ap > bp) resp = 1;
  else if (resp == -1 && bp > ap) resp = 2;
  if (resp == -1 && ab > bb) resp = 1;
  else if (resp == -1 && bb > ab) resp = 2;
  printf("%c\n", resp == 1 ? 'A' : 'B');
  return 0;
}
