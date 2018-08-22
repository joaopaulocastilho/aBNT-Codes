#include <bits/stdc++.h>

using namespace std;

int main(void){
  string a, b;
  for(int i = 0; i < 5; i++){
    cin >> a[i];
  }
  for(int i = 0; i < 5; i++){
    cin >> b[i];
  }
  for(int i = 0; i < (int)a.size(); i++){
    if(a[i] == b[i]){ cout << "N\n"; continue; }
  }
  cout << "Y\n";


  return 0;
}
