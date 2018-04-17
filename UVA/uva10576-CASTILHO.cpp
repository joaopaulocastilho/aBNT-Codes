#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 12

int s, d, resp;

void bt(int i, int tmp[]) {
  int j, ac;
  if (i == 12) {
    for (ac = 0, j = 0; j < 12; j++)
      if (tmp[j]) ac += s;
      else ac -= d;
    resp = max(resp, ac);
    return;
  }
  tmp[i] = 0;
  if (i - 4 >= 0) {
    for (ac = 0, j = i - 4; j <= i; j++) {
      if (tmp[j]) ac += s;
      else ac -= d;
    }
    if (ac >= 0) return;
  }
  bt(i + 1, tmp);
  tmp[i] = 1;
  if (i - 4 >= 0) {
    for (ac = 0, j = i - 4; j <= i; j++) {
      if (tmp[j]) ac += s;
      else ac -= d;
    }
    if (ac >= 0) return;
  }
  bt(i + 1, tmp);
}

int main(void) {
  int tmp[MAX];
  while (scanf("%d %d", &s, &d) != EOF) {
    resp = 0;
    bt(0, tmp);
    if (resp > 0) printf("%d\n", resp);
    else printf("Deficit\n");
  }
  return 0;
}
