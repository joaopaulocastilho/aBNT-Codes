#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
  int tc;
  double m, n, ans = 0;
  char p;
  scanf("%d", &tc);
  while(tc--){
    scanf(" %c %lf %lf", &p, &m, &n);
    if(p == 'r') printf("%.0lf\n", min(m, n));
    else if(p == 'K') printf("%.0lf\n", ceil(m/2)*ceil(n/2));
    else if(p == 'Q'){
      if(m == 2 && n == 2) ans = 1;
      else if(m == 3 && n == 3) ans = 2;
      else ans = min(m, n);
      printf("%.0lf\n", ans);
    }
    else if(p == 'k'){
      if(m == 2 && n == 2) ans = 4;
      else if(m == 1 || n == 1) ans = max(m, n);
      else ans = ceil((m * n)/2);
      printf("%.0lf\n", ans);
    }
  }
  return 0;
}
