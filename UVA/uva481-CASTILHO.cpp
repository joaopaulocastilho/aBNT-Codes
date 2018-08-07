#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

typedef vector<int>vi;

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
  p = pos[pilha.size() - 1];
  while (p >= 0) {
    ans.push_back(v[p]);
    p = pai[p];
  }
  reverse(ans.begin(), ans.end());
  return ans.size();
}

int main(void) {
  int i, a, tmp;
  vi v;
  while (scanf("%d", &tmp) != EOF) v.push_back(tmp);
  a = lis(v);
  printf("%d\n-\n", a);
  for (i = 0; i < a; i++) printf("%d\n", ans[i]);
  return 0;
}
