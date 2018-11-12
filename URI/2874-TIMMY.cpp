#include <iostream>

using namespace std;

int main(void){
  int letras;
  while(cin >> letras){
    getchar();
    while(letras--){
      string str;
      getline(cin, str);
      int ans = 0;
      for(int i = (int)str.size()-1, pot = 1;i >= 0; i--){
	if(str[i] == '1') ans+= pot;
	pot *= 2;
      }
      char pans = ans;
      cout << pans;
    }
    cout << "\n";
  }

  return 0;
}
