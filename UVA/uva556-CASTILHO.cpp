#include <stdio.h>
#include <string.h>

#define MAX 1123
#define val(x, y) ((x) >= 0 && (x) < b && (y) >= 0 && (y) < w) \
  && (maze[(x)][(y)] != 1)

int di[] = { 0, 1, 0, -1 };
int dj[] = { 1, 0, -1, 0 };
int b, w, maze[MAX][MAX];

void turn_right(int &s) { s = (s + 1) % 4; }
void turn_left(int &s) { s = ((s - 1) + 4) % 4; }
int move_on(int i, int j, int s) { return val(i + di[s], j + dj[s]); }

int main(void) {
  int i, j, chegou, cont[MAX][MAX], sentido, resp[11];
  char c;
  while (scanf("%d %d", &b, &w), b) {
    memset(cont, 0, sizeof(cont));
    memset(resp, 0, sizeof(resp));
    for (i = 0; i < b; i++) {
      getchar();
      for (j = 0; j < w; j++) {
        scanf("%c", &c);
        maze[i][j] = c - '0';
      }}
    for (sentido = j = 0, i = b - 1, chegou = 0; !chegou; ) {
      turn_right(sentido);
      while (!move_on(i, j, sentido)) turn_left(sentido);
      i += di[sentido]; j += dj[sentido];
      cont[i][j]++;
      if (i == b - 1 && j == 0) chegou = 1;
    }
    for (i = 0; i < b; i++)
      for (j = 0; j < w; j++)
        if (!maze[i][j] && cont[i][j] <= 4) resp[cont[i][j]]++;
    for (i = 0; i < 5; i++) {
      if (resp[i] < 10) printf(" ");
      printf(" %d", resp[i]);
    }
    printf("\n");
  }
  return 0;
}
