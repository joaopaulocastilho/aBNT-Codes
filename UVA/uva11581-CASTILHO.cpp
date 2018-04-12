#include <stdio.h>

#define valido(x, y) ((x) >= 0 && (x) < 3 && (y) >= 0 && (y) < 3)

int di[] = { 0, 1, 0, -1 };
int dj[] = { 1, 0, -1, 0  };

void f(int g[5][5]) {
  int i, j, k, aux[5][5], nova;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      aux[i][j] = g[i][j];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (nova = k = 0; k < 4; k++) {
	if (valido(i + di[k], j + dj[k])) {
	  nova += aux[i + di[k]][j + dj[k]];
	}}
      g[i][j] = nova % 2;
    }}}

int ok(int g[5][5]) {
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (g[i][j]) return 1;
  return 0;
}

int main(void) {
  int casos, i, j, m[5][5];
  char c;
  scanf("%d", &casos);
  while (casos--) {
    getchar();
    for (i = 0; i < 3; i++) {
      getchar();
      for (j = 0; j < 3; j++) {
	scanf("%c", &c);
	m[i][j] = c - '0';
      }}
    for (i = 0; ok(m); f(m), i++);
    printf("%d\n", i - 1);
  }
  return 0;
}
