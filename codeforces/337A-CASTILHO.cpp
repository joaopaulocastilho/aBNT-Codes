#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 1123
#define INF 112345678

int main(void) {
  int m, n, i, resp = INF;
  scanf("%d %d", &n, &m);
  vector<int> puz(m);
  for (i = 0; i < m; i++) scanf("%d", &puz[i]);
  sort(puz.begin(), puz.end());
  for (i = 0; i <= m - n; i++)
    if (puz[i + n - 1] - puz[i] < resp) resp = puz[i + n - 1] - puz[i];
  printf("%d\n", resp);
  return 0;
}
