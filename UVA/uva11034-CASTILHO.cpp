#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 21
#define LEFT 0
#define RIGHT 1

int main(void) {
  int i, cases, l, m, comp, resp, pb, tmp;
  char pos[MAX];
  scanf("%d", &cases);
  while (cases--) {
    queue<int>esq;
    queue<int>dir;
    scanf("%d %d", &l, &m); l *= 100;
    for (resp = i = 0; i < m; i++) {
      scanf("%d %s", &comp, pos);
      if (pos[0] == 'l') esq.push(comp);
      else dir.push(comp);
    }
    pb = LEFT;
    while (!esq.empty() || !dir.empty()) {
      if (pb == LEFT) {
        tmp = 0;
        while (!esq.empty() && tmp + esq.front() <= l) {
          tmp += esq.front();
          esq.pop();
        }
        resp++;
        pb = RIGHT;
      } else {
        tmp = 0;
        while (!dir.empty() && tmp + dir.front() <= l) {
          tmp += dir.front();
          dir.pop();
        }
        resp++;
        pb = LEFT;
      }}
    printf("%d\n", resp);
  }
  return 0;
}
