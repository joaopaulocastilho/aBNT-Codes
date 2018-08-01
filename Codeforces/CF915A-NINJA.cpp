#include <stdio.h>
#include <algorithm>

using namespace std;

#define INF 112345678

int main(void){
  int n, k, num, ans = INF;

  scanf("%d %d", &n, &k);
  while(n--){
    scanf("%d", &num);
    if(k % num) continue;
    ans = min(ans, k/num);
  }
  printf("%d\n", ans);
  
  return 0;
}
