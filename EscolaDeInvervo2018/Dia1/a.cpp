#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

int main(void) {
  int n, k, i, qtd;
  char c;
  while (scanf("%d %d ", &n, &k), n) {
    vector<char>s;
    for (i = 0; i < n; i++) { scanf("%c", &c); s.push_back(c); }
    for (qtd = 0, i = 1; qtd < k && i < (int)s.size(); i++) {
      if (s[i - 1] < s[i]) {
        s.erase(s.begin() + (i - 1)); qtd++;
        i = max(i - 2, 0);
      }
    }
    for ( ; qtd < k; qtd++) s.erase(s.begin() + (s.size() - 1));
    for (i = 0; i < (int)s.size(); i++) printf("%c", s[i]);
    printf("\n");
  }
  return 0;
}
