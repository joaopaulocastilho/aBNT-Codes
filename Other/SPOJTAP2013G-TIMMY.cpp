#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

int main(void){
  int n; cin >> n;
  int me[MAXV], him[MAXV];
  for(int i = 0; i < n; i++){
    cin >> him[i];
  }
  for(int i = 0; i < n; i++){
    cin >> me[i];
  }
  sort(me, me+n);
  sort(him, him+n);
  int count = 0;
  for(int i = n-1, j = n-1; i >= 0 && j >= 0; i--){
    if(me[i] > him[i]){j--; count++; }
    else{
      while(me[i] <= him[j] && j >= 0) j--;
      if(j != -1){ count++; j--;}
    }
  }
  cout << count << "\n";
  return 0;
}
