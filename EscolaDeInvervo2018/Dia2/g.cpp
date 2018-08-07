#include <bits/stdc++.h>

using namespace std;

typedef struct { int t0, s, r; }paciente_t;

typedef vector<paciente_t>vp;

int main(void) {
  int t, caso, n, maior, maior_r, ind, current, i;
  char op;
  paciente_t tmp;
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    printf("Case #%d:\n", caso);
    scanf("%d", &n);
    vp pa;
    while (n--) {
      scanf(" %c", &op);
      if (op == 'P') {
        scanf("%d %d %d", &tmp.t0, &tmp.s, &tmp.r);
        pa.push_back(tmp);
      } else {
        scanf("%d", &current);
        for (maior = maior_r = ind = i = 0; i < (int)pa.size(); i++) {
          if ((maior == pa[i].s + pa[i].r * (current - pa[i].t0) &&
               maior_r < pa[i].r) ||
              (maior < pa[i].s + pa[i].r * (current - pa[i].t0))) {
                ind = i;
                maior_r = pa[i].r;
                maior = pa[i].s + pa[i].r * (current - pa[i].t0);
          }
        }
        printf("%d %d\n", maior, maior_r);
        pa.erase(pa.begin() + ind);
      }
    }
  }
  return 0;
}
