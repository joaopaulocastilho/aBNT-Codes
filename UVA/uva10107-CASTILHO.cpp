#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
  int n, curr, p, cont = 0;
  vector<int>v;
  while (scanf("%d", &n) != EOF) {
    cont++;
    v.push_back(n);
    p = cont / 2;
    nth_element(v.begin(), v.begin() + p, v.end());
    curr = v[p];
    if (!(cont & 1)) {
      nth_element(v.begin(), v.begin() + (p - 1), v.end());
      curr += v[p - 1]; curr /= 2;
    }
    printf("%d\n", curr);
  }
  return 0;
}
