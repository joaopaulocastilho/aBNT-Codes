#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
  int i, p, n, num;

  scanf("%d %d", &p, &n);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    p += num;
    p = min(100, max(0, p));
  }
  printf("%d\n", p);
  
  return 0;
}
