#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void) {
  int n, m, c, i, j, sala[MAX][MAX], p1, p2;
  int espaco, dist, tem_aluno[MAX];
  scanf("%d %d %d", &n, &m, &c);
  memset(tem_aluno, 0, sizeof(tem_aluno));
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf("%d", &sala[i][j]);
      tem_aluno[j] |= (sala[i][j] != 0);
    }
  //for (i = 0; i < m; i++) printf("%d ", tem_aluno[i]);
  //printf("\n");
  for (espaco = i = 1; espaco && i < m; i++)
    if (tem_aluno[i - 1] && tem_aluno[i]) espaco = 0;
  for (dist = 1, j = 0; j < m; j++) {
    for (i = 0; i < n && sala[i][j] != 1; i++);
    for (p1 = 0, i++; i < n; i++) {
      if (sala[i][j] == 1) {
        if (p1 < c) dist = 0;
        p1 = 0;
      } else p1++;
    }
    for (i = 0; i < n && sala[i][j] != 2; i++);
    for (p2 = 0, i++; i < n; i++) {
      if (sala[i][j] == 2) {
        if (p2 < c) dist = 0;
        p2 = 0;
      } else p2++;
    }
  }
  printf("%c\n", (espaco && dist) ? 'S' : 'N');
  return 0;
}
