#include<stdio.h>

#define MAX 10
#define eh_bis(x) (((x) % 4 == 0) && (x) != 1900)

int main(void) {
  int m[MAX][MAX] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
  };
  int dias[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int data[3], t, i, j, resp, k, newp, perm[MAX][3], flag;
  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    resp = 6; newp = 0;
    scanf("%d-%d-%d", &data[0], &data[1], &data[2]);
    if (data[0] == 4 && data[1] == 5 && data[2] == 1)
      { resp = 1; }
    else {
      for (j = 0; j < 6; j++) {
        for (flag = k = 0; k < newp; k++)
          if (data[m[j][0]] == perm[k][0] &&
              data[m[j][1]] == perm[k][1] &&
              data[m[j][2]] == perm[k][2]) {
            resp--; flag = 1;
          }
        if (flag) continue;
        perm[newp][0] = data[m[j][0]];
        perm[newp][1] = data[m[j][1]];
        perm[newp++][2] = data[m[j][2]];
        if (data[m[j][1]] > 12 || data[m[j][1]] < 1) { resp--; continue; }
        if (data[m[j][1]] == 2 && eh_bis(1900 + data[m[j][2]])) {
          if (data[m[j][0]] > 29 || data[m[j][0]] < 1) { resp--; continue; }
        }
        else if (data[m[j][0]] > dias[data[m[j][1]]] || data[m[j][0]] < 1) {
          resp--; continue;
        }
      }
    }
    printf("Case #%d: %d\n", i, resp);
  }
  return 0;
}
