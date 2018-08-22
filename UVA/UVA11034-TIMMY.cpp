#include <iostream>
#include <queue>

using namespace std;

int main(void){
  queue<int> left, right;
  int tc; cin >> tc;
  int l, m;
  while(tc--){
    cin >> l >> m;
    l *= 100;
    int side, count;
    side = count = 0;
    while(m--){
      int len; string s;
      cin >> len >> s;
      if(s == "left") left.push(len);
      else right.push(len);
    }
    while(!left.empty() || !right.empty()){
      int blen;
      blen = l;
      if(!side)
	while(!left.empty() && blen >= left.front()){ blen -= left.front(); left.pop(); }
      else
	while(!right.empty() && blen >= right.front()){ blen -= right.front(); right.pop(); }
      count++;
      side ^= 1;
    }
    cout << count << "\n";
  }
  return 0;
}
