#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n;
  while(cin >> n){
    double ans = 12.0;
    while(n--){
      double num;
      cin >> num;
      ans = min(ans, num);
    }
    cout << ans << "\n";
  }
  
    

  return 0;
}
