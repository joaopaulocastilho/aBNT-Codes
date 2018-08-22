#include <iostream>

using namespace std;

int main(void){
  int a, b, c, d; cin >> a >> b >> c >> d;
  int  ans = a*b - c*d;
  cout << (ans == 0 ? 0 : (ans > 0 ? -1 : 1)) << endl;
  return 0;
}
