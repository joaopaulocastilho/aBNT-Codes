#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void){
  int n, m, k[MAX][MAX], i, j, resp, atual;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &k[i][j]);
  for (resp = atual = i = 0; i < n; i++) {
    for (atual = j = 0; j < m; j++) atual += k[i][j];
    resp = max(atual, resp);
  }
  for (atual = i = 0; i < m; i++) {
    for (atual = j = 0; j < n; j++)
      atual += k[j][i];
    resp = max(atual, resp);
  }
  printf("%d\n", resp);
  return 0;
}
