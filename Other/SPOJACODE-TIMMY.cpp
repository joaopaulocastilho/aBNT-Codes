#include <bits/stdc++.h>

using namespace std;

const int MAXV = 5123;

long long int memo[MAXV];
string str;

int main(void){
  ios::sync_with_stdio(false);
  while(cin >> str, str != "0"){
    memset(memo, 0, sizeof(memo));
    memo[0] = memo[1] = 1;
    for(int i = 2; i <= (int)str.size(); i++){
      if(str[i-2] == '1' || (str[i-2] == '2' && str[i-1] <= '6')) memo[i] += memo[i-2];
      if(str[i-1] != '0') memo[i] += memo[i-1];
    }
    cout << memo[(int)str.size()] << "\n";
  }
  return 0;
}
