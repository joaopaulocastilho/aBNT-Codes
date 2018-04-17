#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

#define MAX 15

typedef vector<int> vi;

int n, t, flag, v[MAX];

void print_v(vi &ve, int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    if (i) printf("+");
    printf("%d", ve[i]);
  }
  printf("\n");
}

void bt(int id, vi &resp, int qtd, set<vi>&s) {
  int i, tmp;
  if (id > n) return;
  for (tmp = i = 0; i < qtd; i++) tmp += resp[i];
  //for (i = 0; i < qtd; i++) printf("%d ", resp[i]);
  //printf("\n tmp = %d\n", tmp);
  if (tmp == t) {
    if (s.find(resp) != s.end()) return;
    s.insert(resp);
    print_v(resp, qtd); flag = 1;
    return;
  }
  resp[qtd] = v[id];
  bt(id + 1, resp, qtd + 1, s);
  bt(id + 1, resp, qtd, s);
}

int main(void) {
  int i;
  while (scanf("%d %d", &t, &n), t) {
    vi resp(n);
    set<vi>s;
    printf("Sums of %d:\n", t);
    for (flag = 0, i = 0; i < n; i++) scanf("%d", &v[i]);
    bt(0, resp, 0, s);
    if (!flag) printf("NONE\n");
  }
  return 0;
}
