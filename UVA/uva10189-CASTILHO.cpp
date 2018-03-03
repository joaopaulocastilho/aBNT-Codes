#include <stdio.h>

#define MAX 112

char tab[MAX][MAX];
int n, m;
int di[] = { -1, 1, -1, 1, 0, 0, 1, -1 };
int dj[] = { -1, -1, 1, 1, 1, -1, 0, 0 };

int valido(int i, int j) {
  if (i >= 0 && i < n && j >=0 && j < m) return 1;
  return 0;
}

int mapeia(int x, int y) {
  int i, ret = 0;
  for (i = 0; i < 8; i++)
    if (valido(x + di[i], y + dj[i]) && tab[x + di[i]][y + dj[i]] == '*')
      ret++;
  return ret;
}

int main(void) {
  int i, j, casos, first = 1;
  for (casos = 1; scanf("%d %d", &n, &m), m; casos++) {
    for (i = 0; i < n; i++) {
      getchar();
      for (j = 0; j < m; j++)
        scanf("%c", &tab[i][j]);
    }
    if (first) first = 0;
    else printf("\n");
    printf("Field #%d:\n", casos);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (tab[i][j] == '*') printf("*");
        else printf("%d", mapeia(i, j));
      }
      printf("\n");
    }}
  return 0;
}
