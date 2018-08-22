#include <iostream>
#include <string>

using namespace std;


int main(void){
  int tc; cin >> tc;
  string str; cin >> str;
  int a = 0, b = 0;
  for(int i = 0; i < tc; i++){
    if(str[i] == 'A') a++;
    else b++;
  }
  cout << (a > b ? "Anton" : (a < b ? "Danik" : "Friendship")) << "\n";
  return 0;
}
