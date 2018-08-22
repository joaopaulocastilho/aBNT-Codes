#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

int main(void){
  int sz; cin >> sz;
  int zero = 0;
  int um = 0;
  string a, b;

  cin >> a >> b;
  for(int i = 0; i < sz; i++){ if(a[i] == '0') zero++; else um++; }
  
  int ans = 0, countzero = 0, countum = 0;
  for(int i = 0; i < sz; i++){
    if(a[i] == '1' && b[i] == '0'){ ans += zero; countzero++; }
    if(a[i] == '0' && b[i] == '0'){ ans += um; countum++; }
  }
  cout << ans -(countzero * countum) << endl;
  return 0;
}
