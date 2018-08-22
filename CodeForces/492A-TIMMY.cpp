#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int num = 0, i, ans = 0;
  if(n == 1){ cout << 1 << endl; return 0; }
  for(i = 1; n >= ans+(num+i); i++){
    num += i;
    ans += num;
    //cout << ans << endl;
  }
  cout << i-1 << endl; 
  return 0;
}
