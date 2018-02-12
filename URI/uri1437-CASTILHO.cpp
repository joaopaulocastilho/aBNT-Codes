#include <stdio.h>

int main(void) {
  int n, resp; char m;
  while (scanf("%d ", &n), n) {
    for (resp = 1; n--; ) {
      scanf("%c", &m);
      if (m == 'E') resp = ((resp - 1) + 4) % 4;
      else resp = (resp + 1) % 4;
    }
    printf("%c\n", (resp == 0) ? 'O' :
           ((resp == 1) ? 'N' : ((resp == 2)) ? 'L' : 'S'));
  }
  return 0;
}
