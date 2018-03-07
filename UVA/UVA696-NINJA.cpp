#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void){
  double n, m, ans;
  
  while(scanf("%lf %lf", &m, &n), m || n){
    if(n == m && m == 1) ans = 1;
    else if(min(n, m) == 1) ans = max(n, m);
    else if(n == 2 || m == 2){
      if( (((int)(m*n))/4) % 2 == 0) ans = (((int)(m*n))/8) * 4 + ((int)(m*n)) % 4;
      else ans = ceil((m*n)/8) * 4;
    }
    else ans = ceil((m*n)/2);
    printf("%.0lf knights may be placed on a %.0lf row %.0lf column board.\n", ans, m, n);
  }
  
  return 0;
}
