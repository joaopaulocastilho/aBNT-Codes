#include <bits/stdc++.h>

using namespace std;

vector<char>s;

void solve() {
  int i, j;
  s.push_back('a');
  for (i = 'b'; i <= 'z'; i++) {
    s.push_back(i);
    for (j = (int)s.size() - 2; j >= 0; j--) s.push_back(s[j]);
  }
}

int main(void) {
  int n;
  scanf("%d", &n); n--;
  solve();
  printf("%c\n", s[n]);
  return 0;
}
