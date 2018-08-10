#include <bits/stdc++.h>

using namespace std;

const int MAXV = 212345;

int merge_sort(vector<int> &v) {
  int mid = (int)v.size() / 2, inv, ini1, ini2, i, tam;
  vector<int>u1;
  vector<int>u2;
  if (v.size() == 1) return 0;
  for (i = 0; i < mid; i++) u1.push_back(v[i]);
  for (i = mid; i < (int)v.size(); i++) u2.push_back(v[i]);
  inv = merge_sort(u1) + merge_sort(u2);
  ini1 = ini2 = 0;
  u1.push_back(112345678); u2.push_back(112345678);
  for (i = 0; i < (int)v.size(); i++) {
    if (u1[ini1] <= u2[ini2]) {
      v[i] = u1[ini1++];
    } else {
      v[i] = u2[ini2++];
      tam = u1.size() - 1;
      inv += tam - ini1;
    }
  }
  return inv;
}

int main(void) {
  int n, i;
  while (scanf("%d", &n), n) {
    vector<int>v(n);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    printf("%s\n", merge_sort(v) & 1 ? "Marcelo" : "Carlos");
  }
  return 0;
}
