#include<stdio.h>
#include<queue>
using namespace std;

#define MAX 112345

int main(void) {
  int n, k, hotel[MAX], i, resp = 0;
  scanf("%d %d", &n, &k);
  priority_queue< int, vector<int>, less<int> >pq;
  for (i = 0; i < n; i++) scanf("%d", &hotel[i]);
  for (i = n - 1; i >= 0; i--) {
    pq.push(hotel[i]);
    if (i % (k + 1) == k) pq.pop();
  }
  while (!pq.empty()) {
    resp += pq.top();
    pq.pop();
  }
  printf("%d\n", resp);
  return 0;
}
