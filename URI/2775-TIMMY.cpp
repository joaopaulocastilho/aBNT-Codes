#include <iostream>

using namespace std;

int main(void){
  double a, b, c;
  cin >> a >> b >> c;
  if(a < b && a < c) cout << "Otavio\n";
  else if(b < a && b < c) cout << "Bruno\n";
  else if(c < a && c < b) cout << "Ian\n";
  else cout << "Empate\n";

  return 0;
}
