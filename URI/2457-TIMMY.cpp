#include <bits/stdc++.h>

using namespace std;

int main(void){
  char c;
  string s;
  int count = 0, pcount = 0;
  cin >> c;
  while(cin >> s){
    count++;
    int pertence = 0;
    for(int i = 0; i < (int)s.size(); i++){
      if(s[i] == c) pertence = 1;
    }
    if(pertence) pcount++;
  }
  double ans = ((double)pcount/(double)count)*100.0;
  cout << fixed;
  cout << setprecision(1);
  cout << ans << "\n";
  return 0;
}
