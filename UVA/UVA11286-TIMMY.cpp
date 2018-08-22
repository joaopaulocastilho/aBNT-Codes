#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void){
  int tc;
  map<vector<int>, int > mp;
  vector<int> v;
  while(cin >> tc, tc){
    mp.clear();
    while(tc--){
      v.clear();
      for(int i = 0; i < 5; i++){
	int num;
	cin >> num;
	v.push_back(num);
      }
      sort(v.begin(), v.end());
      mp[v]++;
    }
    int bigger = -1;
    for(map<vector<int>, int >::iterator it = mp.begin(); it != mp.end(); ++it)
      if((*it).second > bigger) bigger = (*it).second;
    int count = 0;
    for(map<vector<int>, int >::iterator it = mp.begin(); it != mp.end(); ++it){
      if((*it).second == bigger) count += bigger;
    }
    cout << count << "\n";
  }
  return 0;
}
