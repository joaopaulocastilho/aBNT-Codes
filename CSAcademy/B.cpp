#include <stdio.h>

#define MAX 612

int h, w, x, y;

int intersec(int i, int j) {
  if (i - x >= 0 && j - y >= 0) return 1;
  return 0;
}

int main(void) {
  int i, j, m[MAX][MAX], a[MAX][MAX];
  scanf("%d %d %d %d", &h, &w, &x, &y);
  for (i = 0; i < h + x; i++)
    for (j = 0; j < w + y; j++)
      scanf("%d", &m[i][j]);
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (intersec(i, j)) a[i][j] = m[i][j] - a[i - x][j - y];
      else a[i][j] = m[i][j];
      if (j > 0) printf(" ");
      printf("%d", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
