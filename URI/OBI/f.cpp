#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX 1123

ll bit[MAX][MAX];
int bit2[MAX][MAX];

void update(int x, int y, ll delta){
  for(int i = x; i < MAX; i += i & -i){
    for(int j = y; j < MAX; j += j & -j){
      bit[i][j] += delta;
    }}}

ll sum(int x, int y){
  ll resp = 0;
  for(int i = x; i > 0 ;i -= i & -i){
    for(int j = y; j > 0; j -= j & -j){
      resp += bit[i][j];
    }}
  return resp;
}

void update2(int x, int y, int delta){
  for(int i = x; i < MAX; i += i & -i){
    for(int j = y; j < MAX; j += j & -j){
      bit2[i][j] += delta;
    }}}

int sum2(int x, int y){
  int resp = 0;
  for(int i = x; i > 0 ;i -= i & -i){
    for(int j = y; j > 0; j -= j & -j){
      resp += bit2[i][j];
    }}
  return resp;
}

int main(void) {
  int n, m, l, i, j, l2, tmp2;
  ll tmp, resp = -1;
  char c;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    getchar();
    for (j = 1; j <= m; j++) {
      scanf("%c", &c);
      update(i, j, c == 'C' ? 25 : 12);
      if (c == 'C') update2(i, j, 1);
    }
  }
  scanf("%d", &l2);
  l = l2 - 1;
  for (i = 1; i <= n - l; i++)
    for (j = 1; j <= m - l; j++) {
      tmp2 = sum2(i + l, j + l) - sum2(i + l, j - 1) - sum2(i - 1, j + l) + sum2(i - 1, j - 1);
      if (tmp2 == l2 * l2  || tmp2 == 0) continue;
      tmp = sum(i + l, j + l) - sum(i + l, j - 1) - sum(i - 1, j + l) + sum(i - 1, j - 1);
      resp = max(resp, tmp);
    }
  printf("%lld\n", resp);
  return 0;
}
