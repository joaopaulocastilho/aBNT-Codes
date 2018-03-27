#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void){
  int s, d, x, y, n;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &s, &d);
    y = abs(s+d)/2;
    x = s-y;
    if(x+y == s && abs(x-y) == d && x >= 0 && y >= 0) printf("%d %d\n", max(x, y), min(x, y));
    else printf("impossible\n");
  }

  return 0;
}
