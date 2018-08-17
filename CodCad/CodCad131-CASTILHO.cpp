#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;

int lis(vi &v) {
  int p, i;
  vi pilha;
  for (i = 0; i < (int)v.size(); i++) {
    vi::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
    p = it - pilha.begin();
    if (it == pilha.end()) pilha.push_back(v[i]);
    else pilha[p] = v[i];
  }
  return pilha.size();
}

int main(void) {
  int n, m, i, id, tmp;
  map<int, int>crip;
  vi r;
  scanf("%d %d", &n, &m);
  for (id = i = 0; i < n; i++) { scanf("%d", &tmp); crip[tmp] = id++; }
  for (i = 0; i < m; i++) {
    scanf("%d", &tmp);
    if (crip.find(tmp) == crip.end()) continue;
    r.push_back(crip[tmp]);
  }
  printf("%d\n", lis(r));
  return 0;
}
