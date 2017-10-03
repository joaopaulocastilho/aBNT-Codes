#include<stdio.h>
#include<string.h>

#define MAX 212345

int n, ft[MAX];

int rsq(int i) {
  int ret;
  for (ret = 0 ; i > 0; i -= (i & -i)) ret += ft[i];
  return ret;
}

void update(int i, int v) {
  for ( ; i <= n; i += (i & -i)) {
    ft[i] += v;
  }}

int main(void) {
  int caso, i, resist[MAX], x, y, r, flag, first = 1;
  char c, cl;
  for (caso = 1; scanf("%d", &n), n; caso++) {
    memset(ft, 0, sizeof(ft));
    for (i = 1; i <= n; i++) {
      scanf("%d", &resist[i]);
      update(i, resist[i]);
    }
    if (first) first = 0;
    else printf("\n");
    printf("Case %d:\n", caso);
    for (flag = 1; flag; ) {
      scanf(" %c", &c);
      if (c == 'E') {
        scanf("%c%c", &c, &cl);
        flag = 0;
      } else if (c == 'S') {
        scanf("%d %d", &x, &r);
        update(x, r - resist[x]);
        resist[x] = r;
      } else {
        scanf("%d %d", &x, &y);
        printf("%d\n", rsq(y) - rsq(x - 1));
      }}}
  return 0;
}
