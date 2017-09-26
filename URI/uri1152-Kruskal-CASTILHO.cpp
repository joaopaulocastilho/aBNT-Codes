#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define MAX 212345

typedef pair<int, int>ii;

int n, pai[MAX], ra[MAX];

void Make(int x) { pai[x] = x; ra[x] = 0; }
int Find(int i) { return (pai[i] == i) ? i : (pai[i] = Find(pai[i])); }
int isSameSet(int i, int j) { return Find(i) == Find(j); }
void Union(int i, int j) {
  int x, y;
  if (!isSameSet(i, j)) {
    x = Find(i); y = Find(j);
    if (ra[x] > ra[y]) pai[y] = x;
    else {
      pai[x] = y;
      if (ra[x] == ra[y]) ra[y]++;
    }}}

int kruskal(vector < pair<int, ii> >&LA) {
  int i, ret = 0;
  for (i = 0; i < (int)LA.size(); i++) {
    pair <int, ii> front = LA[i];
    if (!isSameSet(front.second.first, front.second.second)) {
      ret += front.first;
      Union(front.second.first, front.second.second);
    }}
  return ret;
}

int main(void) {
  int m, u, v, w, i, soma, menor;
  while (scanf("%d %d", &n, &m), n) {
    vector < pair<int, ii> >LA;
    soma = 0;
    while (m--) {
      scanf("%d %d %d", &u, &v, &w); soma += w;
      LA.push_back(make_pair(w, ii(u, v)));
    }
    for (i = 0; i < (int)LA.size(); i++) Make(i);
    sort(LA.begin(), LA.end());
    menor = kruskal(LA);
    printf("%d\n", soma - menor);
  }
  return 0;
}
