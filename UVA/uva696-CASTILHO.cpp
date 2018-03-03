#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void) {
  int n, m, resp, aux;
  while (scanf("%d %d", &m, &n), m) {
    if (n == 1 || m == 1) resp = max(n, m);
    else if (n == 2 || m == 2) {
      aux = (n * m) / 4;
      if (aux & 1) resp = ceil((ceil(aux) / 2)) * 4;
      else resp = (aux / 2) * 4 + (m * n) % 4;
    }
    else resp = ceil((double)(m * n) / 2.);
    printf("%d knights may be placed on a %d row %d column board.\n",
           resp, m, n);
  }
  return 0;
}
