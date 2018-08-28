#include <bits/stdc++.h>

using namespace std;

typedef struct { int ini, exec, desc; }aparelho_t;

const int MAXV = 11;
const int total_aparelhos = 10;

int main(void) {
  int i, j, ans, inicio, total, tempo, tmp, flag;
  aparelho_t meu[MAXV], pessoas[MAXV];
  while (scanf("%d %d", &meu[0].exec, &meu[0].desc) != EOF) {
    for (i = 1; i < total_aparelhos; i++)
      scanf("%d %d", &meu[i].exec, &meu[i].desc);
    for (i = 0; i < total_aparelhos; i++)
      scanf("%d %d %d", &pessoas[i].exec, &pessoas[i].desc, &pessoas[i].ini);
    for (ans = i = 0; i < 3; i++) {
      for (j = 0; j < total_aparelhos; j++) {
        inicio = pessoas[j].ini;
        total = pessoas[j].exec + pessoas[j].desc;
        tempo = pessoas[j].exec;
        //Tem que calcular o próximo tempo em que eu posso começar nesse aparelho
        if (ans >= pessoas[j].ini && (ans - inicio) % total <= tempo)
          ans += tempo - (ans - inicio) % total;
        flag = 1;
        if (ans >= inicio) {
          tmp = (ans - inicio) % total;
          pessoas[j].ini = inicio = ans - tmp;
        } else if (ans + meu[i].exec > inicio) {
          pessoas[j].ini = inicio = ans + meu[j].exec;
          flag = 0;
        }
        if (flag && inicio + total < ans + meu[j].exec)
          pessoas[j].ini = ans + meu[j].exec;
        ans += meu[j].exec + meu[j].desc;
      }
    }
    printf("%d\n", ans - meu[9].desc);
  }
  return 0;
}
