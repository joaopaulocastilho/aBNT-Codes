#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define MAX 11234

int main(void) {
  int n, v, i, resp = 1, j, qtd[MAX];
  vector < vector<int> >pos(MAX);
  scanf("%d", &n);
  memset(qtd, 0, sizeof(qtd));
  for (i = 1; i <= n * 2; i++) {
    scanf("%d", &v);
    pos[v].push_back(i);
    qtd[v]++;
  }
  for (i = 1; i <= 5000; i++) {
    if(qtd[i] & 1) resp = 0;
  }
  if (resp) {
    for (i = 1; i <= 5000; i++) {
      for (j = 0; j < (int)pos[i].size(); j += 2)
        printf("%d %d\n", pos[i][j], pos[i][j+1]);
    }
  } else printf("-1\n");
  return 0;
}
