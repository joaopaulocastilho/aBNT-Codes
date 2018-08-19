#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

typedef pair<int, int>ii;

int main(void) {
  int m[MAXV], n, i, v[MAXV];
  scanf("%d", &n);
  priority_queue< ii, vector<ii>, greater<ii> >pq;
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  for (i = 0; i < n; i++) {
    if (pq.empty()) { pq.push(ii(v[i], i)); continue; }
    while (!pq.empty() && pq.top().first < v[i]) {
      m[pq.top().second] = v[i];
      pq.pop();
    }
    pq.push(ii(v[i], i));
  }
  while (!pq.empty()) {
    m[pq.top().second] = -1;
    pq.pop();
  }
  for (i = 0; i < n; i++) {
    if (i) printf(" ");
    if (m[i] != -1) printf("%d", m[i]);
    else printf("*");
  }
  printf("\n");
  return 0;
}
