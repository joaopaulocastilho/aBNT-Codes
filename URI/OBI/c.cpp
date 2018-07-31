#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef long long ll;

typedef struct { int x, y; }ponto;

#define MAX 33
#define qd(x) ((x) * (x))

double exp(double a, int b) {
  if (b == 0) return 1;
  return a * exp(a, b - 1);
}

int main(void) {
  int tc, k, n, i, j;
  double dist, resp;
  ponto s, t;
  char linha[MAX];
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d ", &k, &n);
    for (i = 1; i <= n; i++) {
      fgets(linha, MAX, stdin);
      for (j = 0; linha[j] != '\n'; j++)
        if (linha[j] == 'F') { s.x = i * 10 - 5; s.y = (j + 1) * 10 - 5; }
        else if (linha[j] == 'J') { t.x = i * 10 - 5; t.y = (j + 1) * 10 - 5; }
    }
    //printf("%d %d -- %d %d\n", s.x, s.y, t.x, t.y);
    dist = sqrt(double(qd(abs(s.x - t.x))) + double(qd(abs(s.y - t.y))));
    //printf("%lf\n", dist);
    resp = k / exp(.99, floor(dist));
    printf("%d dBs\n", (int)resp);
  }
  return 0;
}
