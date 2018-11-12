#include <bits/stdc++.h>

using namespace std;

int main(void){
  int tc;
  cin >> tc;

  while(tc--){
    int a, b, c;
    cin >> a >> b >> c;
    double x = (double)(-b)/(double)(2*a);
    //cout << x << "\n";
    double ans = (a*x*x)+(b*x)+c;
    cout << fixed;
    cout << setprecision(2);
    cout << ans << "\n";

  }
  
  return 0;
}
