#include <iostream>
#include <cmath>


using namespace std;

int main(void){
  int l, d; cin >> l >> d;
  int k, p; cin >> k >> p;
  int ans = (l * k) + ((int)floor((double)l/(double)d)*p);
  cout << ans << endl;
  return 0;
}
