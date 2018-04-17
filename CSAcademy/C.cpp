#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX 112345

int main(void) {
  int n, m, i, t, nb, box[MAX], qtd[MAX], n2, atual;
  scanf("%d %d", &n, &m);
  queue<int>q;
  memset(qtd, 0, sizeof(qtd));
  for (i = 0; i < n; i++) scanf("%d", &box[i]);
  for (n2 = i = 0; i < m; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &nb); nb--;
      qtd[nb]++;
      if (box[nb] - qtd[nb] < 0) q.push(nb);
    } else n2++;
  }
  while (!q.empty()) {
    atual = q.front(); q.pop();
    printf("%d\n", atual + 1);
    n2--;
  }
  for (i = 0; i < n2; i++) printf("%d\n", n - 1);
  return 0;
}
