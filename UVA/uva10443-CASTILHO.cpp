#include <stdio.h>

#define MAX 112
#define valido(i, j) ((i) >= 0 && (i) < r && (j) >= 0 && (j) < c)

char g1[2][MAX][MAX];

int di[] = { 0, 1, 0, -1 };
int dj[] = { 1, 0, -1, 0 };

void imprime(int p1, int r, int c) {
  int i, j;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++)
      printf("%c", g1[p1][i][j]);
    printf("\n");
  }
}

char ganhador(char c1, char c2) {
  if (c1 == 'P') {
    if (c2 == 'R' || c2 == 'P') return c1;
    return c2;
  } else if (c1 == 'S') {
    if (c2 == 'P' || c2 == 'S') return c1;
    return c2;
  } else {
    if (c2 == 'S' || c2 == 'R') return c1;
    return c2;
  }
}

int main(void) {
  int casos, first = 1, r, c, n, i, j, primeiro, k, alterou, bk;
  scanf("%d", &casos);
  while (casos--) {
    scanf("%d %d %d ", &r, &c, &n);
    if (first) first = 0;
    else printf("\n");
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++)
        scanf("%c", &g1[0][i][j]);
      getchar();
    }
    for (primeiro = 0; n--; primeiro = !primeiro) {
      for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
          alterou = 0;
          bk = g1[primeiro][i][j];
          for (k = 0; k < 4; k++) {
            if (valido(i + di[k], j + dj[k])) {
              if (!alterou) {
                g1[!primeiro][i][j] =
                  ganhador(g1[primeiro][i][j], g1[primeiro][i + di[k]][j + dj[k]]);
              }
              if (bk != g1[!primeiro][i][j]) alterou = 1;
            }
          }
        }
      }
    }
    imprime(primeiro, r, c);
  }
  return 0;
}
