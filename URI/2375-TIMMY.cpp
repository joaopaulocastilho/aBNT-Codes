#include <iostream>

using namespace std;

int main(void){
  int d; cin >> d;
  int a, l, p; cin >> a >> l >> p;
  if(d <= a && d <= l && d <= p) cout << "S\n";
  else cout << "N\n";

  return 0;
}
