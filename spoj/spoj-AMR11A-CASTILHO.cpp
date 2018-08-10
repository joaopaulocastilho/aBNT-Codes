#include <bits/stdc++.h>

using namespace std;

const int MAXV = 512;
const int INF = 112345678;

int main(void) {
  int t, r, c, i, j, tmp, magrid[MAXV][MAXV], memo[MAXV][MAXV];
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++)
      for (j = 0; j < c; j++) { scanf("%d", &magrid[i][j]); memo[i][j] = INF; }
    for (memo[r - 1][c - 1] = 1, i = r - 1; i >= 0; i--) {
      for (j = c - 1; j >= 0; j--) {
	if (i > 0) {
	  tmp = max(1, memo[i][j] - magrid[i - 1][j]);
	  memo[i - 1][j] = min(memo[i - 1][j], tmp);
	}
	if (j > 0) {
	  tmp = max(1, memo[i][j] - magrid[i][j - 1]);
	  memo[i][j - 1] = min(memo[i][j - 1], tmp);
	}
      }
    }
    //for (i = 0; i < r; i++) {
    // for (j = 0; j < c; j++) printf("%d ", memo[i][j]);
    // printf("\n");
    //}
    printf("%d\n", memo[0][0]);
  }
  return 0;
}
