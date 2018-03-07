#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void){
  int t;
  double m, n;
  char piece;
  
  scanf("%d ", &t);
  while(t--){
    scanf("%c %lf %lf ", &piece, &m, &n);
    if(piece == 'r') printf("%.0lf\n", min(m, n));
    else if(piece == 'k'){
      if(m == n && n == 1) printf("1\n");
      else if(m == n && n == 2) printf("4\n");
      else if(min(m, n) == 1) printf("%.0lf\n", max(m, n));
      else printf("%.0lf\n", ceil((m*n)/2));
    }
    else if(piece == 'Q'){
      if(m == n && n == 2) printf("1\n");
      else if(m == n && n == 3) printf("2\n");
      else printf("%.0lf\n", min(m, n));
    }
    else{
      printf("%.0lf\n", ceil(m/2) * ceil(n/2));
    }
  }
  
  return 0;
}
