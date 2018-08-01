#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);
}

int main(void){
  int t, a, b, tsize;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &a, &b);
    tsize = gcd(max(a, b), min(a, b));
    printf("%d %d\n", tsize, a/tsize * b/tsize);
  }

  return 0;
}
