#include <bits/stdc++.h>

using namespace std;

int main(void){
  string s;
  int first = 1;
  while(cin >> s){
    if(first) first--;
    else cout << " ";
    for(int i = 1; i < (int)s.size(); i+=2){
      cout << s[i];
    }
  }
  cout << "\n";
  return 0;
}
