#include <bits/stdc++.h>

using namespace std;

const int MAXV = 11234;

int main(void){
  int v[MAXV];
  int n;
  int flag = 0;
  cin >> n;
  
  for(int i = 0; i< n; i++){
    cin >> v[i];
  }
  sort(v, v+n);
  
  if(v[0] > 8) cout << "N\n";
  else{
    for(int i = 1; i < n && flag == 0; i++){
      if(v[i] - v[i-1] > 8) flag = 1;
    }
    if(flag == 0) cout << "S\n";
    else cout << "N\n";
  }
  return 0;
}
