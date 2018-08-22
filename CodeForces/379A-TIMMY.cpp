#include <iostream>

using namespace std;

int main(void){
  int a, b; cin >> a >> b;
  for(int i = 1; i <= a; i++)
    if(i % b == 0) a++;
  cout << a << "\n";
  return 0;
}
