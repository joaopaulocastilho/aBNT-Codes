#include <iostream>

using namespace std;

int main(void){
  int n; cin >> n;
  int la, lb; cin >> la >> lb;
  int sa, sb; cin >> sa >> sb;

  if(n >= la && n <= lb && n >=sa && n <= sb)
    cout << "possivel" << endl;
  else
    cout << "impossivel" << endl;
  
  return 0;
}
