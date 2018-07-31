#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
  int i, resp;
  vector<int>v(4);
  for (i = 0; i < 4; i++) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  resp = (v[0] + v[1] > v[2]);
  resp |= (v[0] + v[1] > v[3]);
  resp |= (v[1] + v[2] > v[3]);
  resp |= (v[0] + v[2] > v[3]);
  printf("%c\n", resp ? 'S' : 'N');
  return 0;
}
