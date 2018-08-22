#include <iostream>
#include <set>

using namespace std;

int main(void){
  set<int> st;
  int tc; cin >> tc;
  while(tc--){
    st.clear();
    int n; cin >> n;
    int num;
    while(n--){
      cin >> num;
      st.insert(num);
    }
    cout << (int)st.size() << endl;
  }
  return 0;
}
