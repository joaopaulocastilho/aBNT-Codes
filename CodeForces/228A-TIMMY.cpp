#include <iostream>
#include <set>

using namespace std;

int main(void){
  int a[5];
  set<int> n;
  for(int i = 0; i < 4; i++){
    cin >> a[i];
    n.insert(a[i]);
  }
  cout << 4 - (int)n.size() << endl;
  return 0;
}
