#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void) {
  int casos, n, m, resp;
  char tipo;
  scanf("%d ", &casos);
  while (casos--) {
    scanf("%c %d %d ", &tipo, &n, &m);
    switch (tipo) {
    case 'r': resp = min(m, n); break;
    case 'K': resp = ceil((double)m/2.) * ceil((double)n/2.); break;
    case 'Q':
      if ((m == 2 && n == 2) || (m == 3 && n == 3)) resp = m - 1;
      else resp = min(m, n);
      break;
    case 'k':
      if (m == 1 || n == 1) resp = max(m, n);
      else if (m == 2 && n == 2) resp = 4;
      else resp = ceil((ceil)(m * n) / 2.);
      break;
    }
    printf("%d\n", resp);
  }
  return 0;
}
