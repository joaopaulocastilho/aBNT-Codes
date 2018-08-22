#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(void){
  vector<int> v;
  int tc; cin >> tc;
  int first = 1;
  while(tc--){
    v.clear();
    int n; cin >> n;
    for(int i = 0;i < n; i++){
      int num; cin >> num;
      if((num % 2) != 0) v.push_back(num);
    }
    sort(v.begin(), v.end());
    if(v.size() > 0){
      for(int i = 0, j = (int)v.size()-1; i <= j; i++, j--){
	if(i != 0) cout << " ";
	if(i == j) cout << v[i];
	else cout << v[j] << " " << v[i];
      }
    }
    cout << endl;
  }
  return 0;
}
