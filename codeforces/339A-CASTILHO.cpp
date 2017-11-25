#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
  int cont = 0, first = 1, i; char c;
  vector<int>v;
  while ((c = getchar()) != '\n') {
    if (c == '+') cont++;
    else v.push_back(c - '0');
  }
  sort(v.begin(), v.end());
  for (i = 0; i <= cont; i++) {
    if (first) first = 0;
    else printf("+");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
