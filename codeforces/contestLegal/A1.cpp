#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
  int n, next, caiu, flag, first, i, f1 = 1;
  scanf("%d", &n); next = n;
  priority_queue < int, vector<int>, less<int> > pq;
  for (i = 0; i < n; i++) {
    scanf("%d", &caiu);
    pq.push(caiu);
    if (f1) f1 = 0;
    else printf("\n");
    if (pq.top() != next) continue;
    flag = 1; first = 1;
    while (flag) {
      if (pq.top() == next) {
        if (first) first = 0;
        else printf(" ");
        next--; printf("%d", pq.top());
        pq.pop();
      } else { flag = 0; }
    }
  }
  printf("\n");
  return 0;
}
