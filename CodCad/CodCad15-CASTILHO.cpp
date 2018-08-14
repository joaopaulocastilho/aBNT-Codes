#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int n, i, ant, atual, resp, tmp;
  scanf("%d", &n);
  scanf("%d", &ant);
  for (tmp = resp = i = 1; i < n; i++) {
    scanf("%d", &atual);
    if (atual == ant) tmp++;
    else {
      resp = max(resp, tmp);
      tmp = 1;
    }
    ant = atual;
  }
  resp = max(resp, tmp);
  printf("%d\n", resp);
  return 0;
}
