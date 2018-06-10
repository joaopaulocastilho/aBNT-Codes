#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

#define MAX 112

int main(void) {
  int casos, n, s, q, i, tmp, qi, carpos, resp, flag, acabou;
  scanf("%d", &casos);
  while (casos--) {
    queue<int>station[MAX];
    stack<int>car;
    scanf("%d %d %d", &n, &s, &q);
    for (i = 0; i < n; i++) {
      scanf("%d", &tmp);
      while (tmp--) { scanf("%d", &qi); station[i].push(qi - 1); }
    }
    carpos = 0; resp = 0; acabou = 0;
    while (!acabou) {
      while (!car.empty() && ((int)station[carpos].size() < q ||
                              car.top() == carpos)) {
        if (car.top() != carpos) station[carpos].push(car.top());
        car.pop();
        resp++;
      }
      while (!station[carpos].empty() && (int)car.size() < s) {
        car.push(station[carpos].front());
        station[carpos].pop();
        resp++;
      }
      for (flag = (int)car.empty(), i = 0; i < n; i++) flag &= station[i].empty();
      if (flag) { acabou = 1; continue; }
      carpos = (carpos + 1) % n;
      resp += 2;
    }
    printf("%d\n", resp);
  }
  return 0;
}
