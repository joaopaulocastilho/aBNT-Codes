#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 32

typedef long long ll;

ll calcula_total(char rb[], int tam) {
  int i;
  ll s = 1, ret = 0;
  for (i = 0; i < tam; i++) {
    if (rb[i] == 'S') ret += s;
    else s = s << 1;
  }
  return ret;
}

int main(void) {
  int t, caso, d, tam, flag, resp, i;
  ll dt;
  char rb[MAX];
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    printf("Case #%d: ", caso);
    scanf("%d ", &d);
    fgets(rb, MAX, stdin);
    rb[strlen(rb) - 1] = '\0'; tam = strlen(rb);
    for (resp = 0, flag = 1, dt = calcula_total(rb, tam); flag && dt > d; resp++) {
      for (i = tam - 1; i && (rb[i] != 'S' || rb[i - 1] != 'C'); i--);
      if (i == 0) { flag = 0; break; }
      swap(rb[i], rb[i - 1]);
      dt = calcula_total(rb, tam);
    }
    if (flag) printf("%d\n", resp);
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}
