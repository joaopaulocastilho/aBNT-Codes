#include <bits/stdc++.h>

using namespace std;

const int MAXV = 312345;

typedef vector<int>vi;

vi ans;

bool comp(int a, int b) { return (a <= b); }

int lis(vi &v) {
  int pos[MAXV], pai[MAXV], p, i;
  vi pilha;
  for (i = 0; i < (int)v.size(); i++) {
    vi::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i], comp);
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
  int n, i;
  char s[MAXV];
  vi v;
  scanf("%s", s); n = strlen(s);
  for (i = 0; i < n; i++) v.push_back(s[i] - 'A');
  printf("%d\n", lis(v));
  return 0;
}
