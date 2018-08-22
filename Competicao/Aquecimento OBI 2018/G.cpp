#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define INF 112

int bt(string num){
  if(num.size() == 0) return INF;
  int ans = INF;
  int inum = atoi(num.c_str());
  if(inum % 6 == 0) return 1;
  string str;
  for(int i = 0; i < (int)num.size(); i++){
    str.clear();
    for(int j = 0; j < (int)num.size(); j++){
      if(j == i) continue;
      str.push_back(num[j]);
    }
    ans = min(ans, bt(str)+1);
  }
  return ans;
}

int main(void){
  int tc; cin >> tc;
  while(tc--){
    int ans = INF;
    string num; cin >> num;
    int inum = atoi(num.c_str());
    if(inum % 6 == 0){ cout << 0 << endl; continue; }
    string str;
    for(int i = 0; i < (int)num.size(); i++){
      str.clear();
      for(int j = 0; j < (int)num.size(); j++){
	if(j == i) continue;
	str.push_back(num[j]);
      }
      ans = min(ans, bt(str)+1);
    }
    if(ans == INF) cout << "Cilada" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
