#include <stdio.h>

int main(void) {
  int v1[11], v2[11], i, valido = 1;
  for (i = 0; i < 5; i++) scanf("%d", &v1[i]);
  for (i = 0; i < 5; i++) scanf("%d", &v2[i]);
  for (i = 0; i < 5; i++)
    valido &= (v1[i] ^ v2[i]);
  printf("%c\n", valido ? 'Y' : 'N');
  return 0;
}
