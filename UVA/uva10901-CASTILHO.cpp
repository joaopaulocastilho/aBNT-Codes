#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int>ii;

#define MAX 11234
#define LEFT 0
#define RIGHT 1

int main(void) {
  int cases, n, t, m, i, pb, tempo, tb, qtdb, first = 1, resp[MAX];
  char pos[21];
  scanf("%d", &cases);
  while (cases--) {
    if (first) first = 0;
    else printf("\n");
    memset(resp, 0, sizeof(resp));
    scanf("%d %d %d", &n, &t, &m);
    queue<ii>esq;
    queue<ii>dir;
    for (i = 0; i < m; i++) {
      scanf("%d %s", &tempo, pos);
      if (pos[0] == 'l') esq.push(ii(i, tempo));
      else dir.push(ii(i, tempo));
    }
    pb = LEFT; qtdb = 0; tb = 0;
    while (!dir.empty() || !esq.empty()) {
      if (pb == LEFT) {
        if (esq.empty()) {
          pb = RIGHT;
          tb = max(tb + t, dir.front().second + t);
        } else if (!dir.empty() && pb == LEFT && (dir.front().second < esq.front().second || esq.empty()) && tb < esq.front().second) {
            pb = RIGHT;
            tb = max(tb + t, dir.front().second + t);
          }
      } else {
        if (dir.empty()) {
          pb = LEFT;
          tb = max(tb + t, esq.front().second + t);
        } else if (!esq.empty() && pb == RIGHT && (dir.front().second > esq.front().second || dir.empty()) && tb < dir.front().second) {
          pb = LEFT;
          tb = max(tb + t, esq.front().second + t);
        }
      }
      if (pb == LEFT) {
        tb = max(tb, esq.front().second);
        while (!esq.empty() && tb >= esq.front().second && qtdb < n) {
          qtdb++;
          //printf("Teste: %d, %d", esq.front().first, tb + t);
          resp[esq.front().first] = tb + t;
          esq.pop();
        }
        pb = RIGHT;
        qtdb = 0;
        tb += t;
      } else {
        tb = max(tb, dir.front().second);
        while (!dir.empty() && tb >= dir.front().second && qtdb < n) {
          qtdb++;
          resp[dir.front().first] = tb + t;
          dir.pop();
        }
        pb = LEFT;
        qtdb = 0;
        tb += t;
      }
    }
    for (i = 0; i < m; i++) printf("%d\n", resp[i]);
  }
  return 0;
}
