#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void) {
  int resp = 0, x, y, i, li, ls;
  scanf("%d %d", &x, &y); li = min(x, y); ls = max(x, y);
  for (i = li; i <= ls; i++) if (i % 13) resp += i;
  printf("%d\n", resp);
  return 0;
}
