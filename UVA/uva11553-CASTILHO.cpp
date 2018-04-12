#include <stdio.h>
#include <algorithm>

using namespace std;

#define TAM 8
#define INF 112345678

int main(void) {
  int i, j, t, n, m[TAM][TAM], atual, resp;
  int perms[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (resp = INF, i = 0; i < n; i++)
      for (j = 0; j < n; j++) scanf("%d", &m[i][j]);
    do {
      atual = 0;
      for (i = 0; i < n; i++) { atual += m[i][perms[i]]; }
      resp = min(resp, atual);
    } while (next_permutation(perms, perms + n));
    printf("%d\n", resp);
  }
  return 0;
}
