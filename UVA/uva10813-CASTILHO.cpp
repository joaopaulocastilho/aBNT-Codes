#include <stdio.h>
#include <string.h>

int cartela[6][6], vv[6], vh[6], diagonal1, diagonal2;

int coluna_num(int n) {
  if (n <= 15) return 0;
  if (n <= 30) return 1;
  if (n <= 45) return 2;
  if (n <= 60) return 3;
  return 4;
}

int linha_num(int n) {
  int c, l;
  c = coluna_num(n);
  for (l = 0; l < 5; l++)
    if (cartela[l][c] == n) return l;
  return 0;
}

int diagonal1_num(int n) {
  int i;
  for (i = 0; i < 5; i++)
    if (cartela[i][i] == n) return 1;
  return 0;
}

int diagonal2_num(int n) {
  int i, j;
  for (i = 0, j = 4; i < 5; i++, j--)
    if (cartela[i][j] == n) return 1;
  return 0;
}

int terminou() {
  int i;
  for (i = 0; i < 5; i++) {
    if (i == 2 && (vv[i] == 4 || vh[i] == 4)) return 1;
    if (vv[i] == 5 || vh[i] == 5) return 1;
  }
  if (diagonal1 == 4 || diagonal2 == 4) return 1;
  return 0;
}

int main(void) {
  int n, i, j, num, possui[81], flag;
  scanf("%d", &n);
  while (n--) {
    memset(vv, 0, sizeof(vv));
    memset(vh, 0, sizeof(vh));
    memset(possui, 0, sizeof(possui));
    diagonal1 = diagonal2 = 0;
    for (i = 0; i < 5; i++)
      for (j = 0; j < 5; j++) {
        if (i == 2 && j == 2) j++;
        scanf("%d", &cartela[i][j]);
        possui[cartela[i][j]] = 1;
      }
    cartela[2][2] = 112;
    /*for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++)
        printf("%d ", cartela[i][j]);
      printf("\n");
      }*/
    for (flag = i = 1; i <= 75; i++) {
      scanf("%d", &num);
      if (possui[num]) {
        vv[coluna_num(num)]++;
        vh[linha_num(num)]++;
        diagonal1 += diagonal1_num(num);
        diagonal2 += diagonal2_num(num);
        //printf("num = %d, diagonal1 = %d, diagonal2 = %d, vertical_atual = %d vertical, hori_atual = %d\n",
        // num, diagonal1, diagonal2, vv[coluna_num(num)], vh[linha_num(num)]);
      }
      if (flag && terminou()) {
         printf("BINGO after %d numbers announced\n", i);
        flag = 0;
      }}}
  return 0;
}
