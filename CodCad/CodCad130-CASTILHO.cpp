#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;

const int MAXV = 112345;

void lis(vi &v, vi& ans) {
  int p, i;
  vi pilha;
  for (i = 0; i < (int)v.size(); i++) {
    vi::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
    p = it - pilha.begin();
    if (it == pilha.end()) pilha.push_back(v[i]);
    else pilha[p] = v[i];
    ans.push_back(p + 1);
  }
}

int main(void) {
  int i, n, ans;
  vi ans1, ans2;
  scanf("%d", &n);
  vi v(n);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  lis(v, ans1);
  reverse(v.begin(), v.end());
  lis(v, ans2);
  reverse(ans2.begin(), ans2.end());
  for (ans = -1, i = 0; i < n; i++)
    ans = max(ans, min(ans1[i], ans2[i]));
  printf("%d\n", ans * 2 - 1);
  return 0;
}
