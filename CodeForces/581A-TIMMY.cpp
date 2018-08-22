#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  int a, b; cin >> a >> b;
  int ansa = min(a, b);
  int ansb = (a > b ? a-b : b-a)/2;
  cout << ansa << " " << ansb << "\n";
  return 0;
}
