#include <bits/stdc++.h>

using namespace std;

int main(void){
  int tc, dif;
  int n1, n2, r;
  string c, j;
  
  cin >> tc;
  while(tc--){
    cin >> n1 >> c >> n2 >> j >> r;
    
    if(c == "+")
      dif = abs(r - (n1 + n2));
    if(c == "-")
      dif = abs(r - (n1 - n2));
    if(c == "x")
      dif = abs(r - (n1 * n2));
    
    cout << "E";
    for(int i = 0; i < dif; i++) cout << "r";
    cout << "ou!\n";
  }
  return 0;
}
