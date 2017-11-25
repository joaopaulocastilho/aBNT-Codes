#include <stdio.h>

int main(void) {
  int n, caso, s, m1, m2, i;
  scanf("%d", &n);
  for (caso = 1; caso <= n; caso++) {
    for (m1 = m2 = i = 0; i < 3; i++) {
      scanf("%d", &s);
      if (s > m1) { m2 = m1; m1 = s; }
      else if (s > m2) m2 = s;
    }
    printf("Case %d: %d\n", caso, m2);
  }
  return 0;
}
