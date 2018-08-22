#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, d;
  while(cin >> n >> d, n){
    string str;
    cin >> str;
    for(int i = 0; i < n-1 && d > 0;){
      if(str[i] - '0' < str[i+1] - '0'){
	//cout << str << endl;
	str.erase(str.begin()+i);
	d--; i = i - (i != 0);
      }
      else i++;
    }
    while(d--){
      //cout << str << endl;
      str.erase(str.begin()+str.size()-1);
    }
    cout << str << endl;
  }
  return 0;
}
