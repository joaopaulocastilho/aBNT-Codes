#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
  int m, n, ans, aux;
  while(scanf("%d %d", &m, &n), m != 0){
    if(m == 2 || n == 2){
      aux = ((m * n)/4);
      if(aux % 2 == 0) ans = (((aux)/2)*4) + ((m * n) % 4);
      else ans = (int)ceil((double)aux/2)*4;
      printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
    }
    else if(m == 1 || n == 1) printf("%d knights may be placed on a %d row %d column board.\n", max(m,n), m, n);
    else printf("%d knights may be placed on a %d row %d column board.\n", (int) ceil((double)(m * n)/2), m, n);
  }
  return 0;
}
