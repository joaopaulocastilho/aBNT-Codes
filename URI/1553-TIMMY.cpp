#include <iostream>
#include <map>

using namespace std;

int main(void){
  int n, k;
  map<int, int> mp;
  while(cin >> n >> k, n+k > 0){
    mp.clear();
    while(n--){
      int num;
      cin >> num;
      mp[num]++;
    }
    int count = 0;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
      if(it->second >= k) count++;
    cout << count << endl;
  }
  return 0;
}
