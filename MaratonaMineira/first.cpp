#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 112345
#define INF 112345678

int main(void) {
  int n, i, j, dado[MAX], possib[11][11], resp, tmp;
  scanf("%d", &n);
  for (i = 1; i <= 6; i++)
    for (j = 1; j <= 6; j++) {
      if (i == j) possib[i][j] = 0;
      else if (i + j == 7) possib[i][j] = 2;
      else possib[i][j] = 1;
    }
  /*
  for (i = 1; i <= 6; i++) {
    printf("%d: ", i);
    for (j = 1; j <= 6; j++)
      printf("%d ", possib[i][j]);
    printf("\n");
    }*/
  for (i = 0; i < n; i++) scanf("%d", &dado[i]);
  for (resp = INF, i = 1; i <= 6; i++) {
    for (tmp = j = 0; j < n; j++) {
      tmp += possib[dado[j]][i];
    }
    resp = min(resp, tmp);
  }
  printf("%d\n", resp);
  return 0;
}
