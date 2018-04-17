#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 11

int row[MAX], row_aux[MAX], resp;

int place(int r, int c) {
  int i;
  for (i = 0; i < c; i++)
    if (row_aux[i] == r || abs(row_aux[i] - r) == abs(i - c))
      return 0;
  return 1;
}

void bt(int c) {
  int curr, i, r;
  if (c == 8) {
    for (curr = i = 0; i < 8; i++)
      if (row[i] != row_aux[i]) curr++;
    resp = min(resp, curr);
    return;
  }
  for (r = 0; r < 8; r++)
    if (place(r, c)) { row_aux[c] = r; bt(c + 1); }
}

int main(void) {
  int i, caso = 1;
  while (scanf("%d", &row[0]) != EOF) {
    for (row[0]--, i = 1; i < 8; i++) { scanf("%d\n", &row[i]); row[i]--; }
    memset(row_aux, 0, sizeof(row_aux));
    resp = 11; bt(0);
    printf("Case %d: %d\n", caso, resp); caso++;
  }
  return 0;
}
