#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  int n; cin >> n;
  for(int i = 0; i< n; i++){
    int a, b; cin >> a >> b;
    int ans = (floor((double)a/3)*floor((double)b/3));
    cout << ans << endl;
  }


  return 0;
}
