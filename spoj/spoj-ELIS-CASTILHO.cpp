#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;

const int MAXV = 112;

vi ans;

int lis(vi &v) {
  int pos[MAXV], pai[MAXV], p, i;
  vi pilha;
  for (i = 0; i < (int)v.size(); i++) {
    vi::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
    p = it - pilha.begin();
    if (it == pilha.end()) pilha.push_back(v[i]);
    else pilha[p] = v[i];
    pos[p] = i;
    if (p == 0) pai[i] = -1;
    else pai[i] = pos[p - 1];
  }
  return pilha.size();
}

int main(void) {
  int n, i, a;
  scanf("%d", &n);
  vi v(n);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  a = lis(v);
  printf("%d\n", a);
  return 0;
}
