#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
  int a1, b1, a2, b2, la, lb;
  scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
  la = min(max(a1, b1), max(a2, b2));
  lb = min(a1, b1) + min(a2, b2);
  (la > lb) ? printf("%d\n", lb*lb) : printf("%d\n", la*la);
  return 0;
}
