#include <stdio.h>

int main(void) {
  int t, com, i, resp = 0;
  scanf("%d", &t);
  for (i = 0; i < 5; i++) {
    scanf("%d", &com);
    resp += (com == t);
  }
  printf("%d\n", resp);
  return 0;
}
