#include <iostream>

using namespace std;

int main(void){
  int a, b, c, d; cin >> a >> b >> c >> d;
  int ans = 0;
  if(a + b > c && a + c > b && b + c > a) ans = 1;
  if(a + b > d && a + d > b && b + d > a) ans = 1;
  if(a + d > c && a + c > d && d + c > a) ans = 1;
  if(d + b > c && d + c > b && b + c > d) ans = 1;
  cout << (ans == 1 ? "S\n" : "N\n");

  return 0;
}
