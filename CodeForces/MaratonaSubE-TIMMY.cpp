#include <bits/stdc++.h>

using namespace std;

int main(void){
  string cifr, crib;
  int count = 0;
  cin >> cifr >> crib;
  for(int i = 0;i <= (int)cifr.size() - (int)crib.size(); i++){
    int flag = 1;
    for(int j = 0; j < (int)crib.size(); j++){
      if(cifr[i+j] == crib[j]){ flag = 0; break; }
    }
    if(flag) count++;
  }
  cout << count << "\n";
  return 0;
}
    
