#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
  int a, b, c, ans;

  scanf("%d %d %d", &a, &b, &c);
  ans = max(a+b*c, a*(b+c));
  ans = max(ans, a*b*c);
  ans = max(ans, (a+b)*c);
  ans = max(ans, a+b+c);
  printf("%d\n", ans);

  return 0;
}
