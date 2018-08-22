#include <bits/stdc++.h>

using namespace std;

const int MAXV = 11234;

int main(void){
  int tc; cin >> tc;
  long long int v[MAXV], pd[MAXV];
  for(int caso = 1; caso <= tc; caso++){
    memset(pd, 0, sizeof(pd));
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    
    pd[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--){
      pd[i] = max(pd[i+2]+v[i], pd[i+1]);
    }
    cout << "Case " << caso << ": ";    
    cout << pd[0] << "\n";
  }
  return 0;
}
