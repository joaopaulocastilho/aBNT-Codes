#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void){
  string str;
  int tc; cin >> tc;
  while(tc--){
    cin >> str;
    cout << fixed;
    cout << setprecision(2);
    cout << ((double)str.size()/100.0) << endl;
  }
  return 0;
}
