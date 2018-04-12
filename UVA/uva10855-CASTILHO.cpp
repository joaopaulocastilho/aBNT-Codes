#include <stdio.h>
#include <string.h>

#define MAX 112

int m;
char m1[MAX][MAX], m2[MAX][MAX];

int compara(int i1, int j1) {
  int i, j;
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
      if (m1[i + i1][j + j1] != m2[i][j]) return 0;
  return 1;
}

void transp() {
  int i, j, in, jn;
  char aux[MAX][MAX];
  for (i = 0, jn = m - 1; i < m; i++, jn--)
    for (in = j = 0; j < m; j++, in++)
      aux[in][jn] = m2[i][j];
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
      m2[i][j] = aux[i][j];
}

int main(void) {
  int n, i, j, k, resp[11];
  char c;
  while (scanf("%d %d", &n, &m), n) {
    memset(resp, 0, sizeof(resp));
    for (i = 0; i < n; i++) {
      getchar();
      for (j = 0; j < n; j++) {
	scanf("%c", &c);
	m1[i][j] = c;
      }}
    for (i = 0; i < m; i++) {
      getchar();
      for (j = 0; j < m; j++) {
	scanf("%c", &c);
	m2[i][j] = c;
      }}
    for (k = 0; k < 4; k++) {
      for (i = 0; i <= n - m; i++) {
	for (j = 0; j <= n - m; j++) {
	  resp[k] += compara(i, j);
	}
      }
      transp();
    }
    for (i = 0; i < 4; i++) {
      if (i) printf(" ");
      printf("%d", resp[i]);
    }
    printf("\n");
  }
  return 0;
}
