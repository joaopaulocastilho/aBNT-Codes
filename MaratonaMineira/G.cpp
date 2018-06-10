#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int>ii;

int main(void) {
  int n, di, ti, i, resp;
  vector<ii>mon;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &di, &ti);
    mon.push_back(ii(di, ti));
  }
  sort(mon.begin(), mon.end());
  //for (i = 0; i < n; i++) printf("%d %d\n", mon[i].first, mon[i].second);
  for (resp = i = 1; i < n; i++)
    resp &= (mon[i - 1].second >= mon[i].second);
  printf("%c\n", resp ? 'S' : 'N');
  return 0;
}
