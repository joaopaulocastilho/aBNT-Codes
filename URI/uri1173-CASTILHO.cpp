#include<stdio.h>

int main(void) {
  int v, i;
  scanf("%d", &v);
  for (i = 0; i < 10; i++, v *= 2) printf("N[%d] = %d\n", i, v);
  return 0;
}
