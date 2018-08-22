#include <iostream>
#include <set>

using namespace std;

int main(void){
  set<int> st;
  int num;
  int n, p; cin >> n >> p;
  for(int i = 0; i < p; i++){
    cin >> num;
    st.insert(num);
  }
  for(int i = 0; i < n; i++){
    cin >> num;
    if(st.find(num) != st.end()) cout << 0;
    else{ st.insert(num); cout << 1; }
    cout << endl;
  }
  return 0;
}
