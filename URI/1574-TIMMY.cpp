#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void){
  int tc; cin >> tc;
  while(tc--){
    map<int, int> mp;
    mp.clear();
    string s;
    int p = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> s;
      if(s == "LEFT"){ p--; mp[i] = -1; }
      else if(s == "RIGHT"){p++; mp[i] = 1; }
      else{
	int num;
	cin >> s; cin >> num;
	p += mp[num];
	mp[i] = mp[num];
      }
    }
    cout << p << endl;
  }

  return 0;
}
