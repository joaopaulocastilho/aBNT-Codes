#include <stdio.h>
#include <algorithm>

using namespace std;

#define INF 112345678

int main(void){
  int num, n, ans = INF;

  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    ans = min(ans, num);
  }
  printf("%d\n", ans);
  
  return 0;
}
