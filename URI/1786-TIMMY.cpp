#include <iostream>

using namespace std;

int main(void){
  string str;
  int ans, ans2;
  while(cin >> str){
    ans = ans2 = 0;
    for(int i = 0, idx = 9; i < 9; i++, idx--){
      ans += idx*(str[i] - '0');
      ans2 += (i+1) * (str[i] - '0');
    }
    int b1 = ans2%11;
    b1 = (b1 == 10 ? 0 : b1);
    int b2 = ans%11;
    b2 = (b2 == 10 ? 0 : b2);
    for(int i = 0, count = 0; i < 12; i++){
      if(i == 3 || i == 7) cout << '.';
      else if(i == 11) cout << '-';
      else cout << str[count++];
    }
    cout << b1 << b2;
    cout << endl;
  }

  return 0;
}
