#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int tc; cin >> tc;
    while(tc--){
      int num;
      cin >> num;
      cout << (int)ceil((double)num/2.0) << endl;
    }
    
    return 0;
}
