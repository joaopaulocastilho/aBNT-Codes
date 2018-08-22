#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
  float num; cin >> num;
  float ans = 0;
  cout << fixed;
  cout << setprecision(2);
  if(num <= 2000){ cout << "Isento\n"; return 0;}
  if(num > 2000 && num >= 3000){ ans += 1000*0.08;}
  else if(num > 2000){ ans += (num-2000)*0.08; }
  if(num > 3000 && num >= 4500){ ans += 1500 * 0.18; }
  else if(num > 3000){ ans += (num-3000)*0.18;}
  if(num > 4500){ ans += (num-4500)* 0.28;}
  cout << "R$ " << ans << endl;
  return 0;
}
