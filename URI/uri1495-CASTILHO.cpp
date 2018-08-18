#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef vector<ii>vii;

int cmp(ii a, ii b) {
  int dif1 = a.second - a.first, dif2 = b.second - b.first;
  return dif1 < dif2;
}

int main(void) {
  int n, g, i, s, r, dif, ans;
  while (scanf("%d %d", &n, &g) != EOF) {
    vii v;
    for (ans = i = 0; i < n; i++) {
      scanf("%d %d", &s, &r);
      if (s > r) { ans += 3; continue; }
      v.push_back(ii(s, r));
    }
    sort(v.begin(), v.end(), cmp);
    for (i = 0; i < (int)v.size(); i++) {
      dif = v[i].second - v[i].first;
      if (g > dif) { g -= (dif + 1); ans += 3; }
      else if (g == dif) { g = 0; ans++; }
    }
    printf("%d\n", ans);
  }
  return 0;
}
