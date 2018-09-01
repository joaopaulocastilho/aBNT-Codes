#include <bits/stdc++.h>

using namespace std;

typedef struct { int x, y, tipo; }ponto_t;

const int MAXV = 1123456;

ponto_t ponto[MAXV];

int compx(ponto_t a, ponto_t b) { return (a.x < b.x); }
int compy(ponto_t a, ponto_t b) { return (a.y < b.y); }

int main(void) {
  int n, i, j, total0, total1, linha0, linha1, ant0, ant1, ans1, ans2, ans = 0;
  char c;
  scanf("%d", &n);
  for (total0 = total1 = i = 0; i < n; i++) {
    scanf("%d %d %c", &ponto[i].x, &ponto[i].y, &c);
    ponto[i].tipo = (c == 'b');
    total0 += (c != 'b');
    total1 += (c == 'b');
  }
  sort(ponto, ponto + n, compx);
  for (ant0 = ant1 = i = 0; i < n; i++) {
    linha0 = !ponto[i].tipo;
    linha1 = ponto[i].tipo;
    for (j = i; j + 1 < n && ponto[j].x == ponto[j + 1].x; j++) {
      linha0 = !ponto[j + 1].tipo;
      linha1 = ponto[j + 1].tipo;
    }
    ans1 = ant0 + (total1 - ant1 - linha1) + max(linha0, linha1);
    ans2 = ant1 + (total0 - ant0 - linha0) + max(linha0, linha1);
    ans = max(ans, max(ans1, ans2));
    ant0 += linha0; ant1 += linha1;
  }
  sort(ponto, ponto + n, compy);
  for (ant0 = ant1 = i = 0; i < n; i++) {
    linha0 = !ponto[i].tipo;
    linha1 = ponto[i].tipo;
    for (j = i; j + 1 < n && ponto[j].y == ponto[j + 1].y; j++) {
      linha0 = !ponto[j + 1].tipo;
      linha1 = ponto[j + 1].tipo;
    }
    ans1 = ant0 + (total1 - ant1 - linha1) + max(linha0, linha1);
    ans2 = ant1 + (total0 - ant0 - linha0) + max(linha0, linha1);
    ans = max(ans, max(ans1, ans2));
    ant0 += linha0; ant1 += linha1;
  }
  printf("%d\n", ans);
  return 0;
}
