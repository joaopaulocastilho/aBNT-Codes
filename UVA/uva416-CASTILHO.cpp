#include <stdio.h>

#define MAX 15

int n, ans, m[MAX][MAX];

int cola[MAX][MAX] = {
  { 1, 1, 1, 1, 1, 1, 0 }, //0
  { 0, 1, 1, 0, 0, 0, 0 }, //1
  { 1, 1, 0, 1, 1, 0, 1 }, //2
  { 1, 1, 1, 1, 0, 0, 1 }, //3
  { 0, 1, 1, 0, 0, 1, 1 }, //4
  { 1, 0, 1, 1, 0, 1, 1 }, //5
  { 1, 0, 1, 1, 1, 1, 1 }, //6
  { 1, 1, 1, 0, 0, 0, 0 }, //7
  { 1, 1, 1, 1, 1, 1, 1 }, //8
  { 1, 1, 1, 1, 0, 1, 1 }  //9
};

int acendeu(int id, int col) {
  int i;
  for (i = id; i < n; i++) if (m[i][col]) return 1;
  return 0;
}

void bt(int id, int num) {
  int flag, i, j;
  if (id == n) { ans = 0; return; }
  if (num == -1) return;
  for (i = 9; id == 0 && i >= n - 1; i--) {
    for (flag = 1, j = 0; j < 7; j++) {
      if (m[id][j] && !cola[i][j]) { flag = 0; break; }
      if (acendeu(id + 1, j) && !m[id][j] && cola[i][j])
        { flag = 0; break; }
    }
    if (flag) bt(id + 1, i - 1);
  }
  if (id == 0) return;
  for (i = 0; i < 7; i++) {
    if (m[id][i] && !cola[num][i]) return;
    if (acendeu(id + 1, i) && !m[id][i] && cola[num][i]) return;
  }
  bt(id + 1, num - 1);
}

int main(void) {
  int i, j;
  char c;
  while (scanf("%d", &n), n) {
    for (i = 0; i < n; i++) {
      getchar();
      for (j = 0; j < 7; j++) {
        scanf("%c", &c);
        m[i][j] = (c == 'Y');
      }}
    ans = 1; bt(0, 9);
    if (ans) printf("MIS");
    printf("MATCH\n");
  }
  return 0;
}
