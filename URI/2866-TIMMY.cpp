#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n; cin >> n;
  while(n--){
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size();i++){
      if(s[i] >= 'A' && s[i] <= 'Z') s.erase(s.begin()+i--);
    }
    for(int i = ((int)s.size())-1; i >= 0; i--){
      cout << s[i];
    }
    cout << "\n";
  }

  return 0;
}

	    
