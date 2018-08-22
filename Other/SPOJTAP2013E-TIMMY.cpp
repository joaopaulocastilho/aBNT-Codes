#include <bits/stdc++.h>

using namespace std;

const int MAXV = 11234567;

int v[MAXV];
string str;

int deco(int i, int j){
  int sum = 0;
  for(int k = j, l = 1; k >= i; k--){
    //cout << str[k];
    sum += (str[k]-'0') * l;
    l *= 2;
  }
  //cout << "\n";
  //cout << sum << "\n";
  return sum;
}

int main(void){
  int n; cin >> n;
  while(n--){
    cin >> str;
    int ans = -1;
    for(int j = 0, i = 0, l = 2; j < 17 && ans == -1; j++){
      memset(v, 0, sizeof(v));
      for(i = 0; (i+j) < (int)str.size(); i++){
	v[deco(i, i+j)] = 1;
	//cout << i << " " << i+j << "\n";
	//cout << deco(i, i+j) << "\n";
      }
      for(int k = 0; k < l; k++){
	//cout << k << " " << v[k] << " | ";
	if(v[k] == 0){ ans = j+1; break; }
      }
      //cout << "\n";
      l *= 2;
    }
    cout << ans << "\n";
  }

  return 0;
}
