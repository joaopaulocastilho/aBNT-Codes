#include <bits/stdc++.h>

using namespace std;

int main(void){
  int a, b, i;
  cin >> a >> b;
  for(i = 0; i <= 100 && a <= b; i++){
    a *= 3;
    b *= 2;
  }
  cout << i << "\n";
  return 0;
}
