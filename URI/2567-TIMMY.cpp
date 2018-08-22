#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
  string str;
  cin >> str;
  int count = 0;
  int num = 0;
  for(int i = 0;i < (int)str.size(); i++){
    if(i < (int)str.size()-1 && str[i+1] == '0'){
      num += 10*(str[i]-'0');
      i++;
    }
    else num += str[i]-'0';
    count ++;
  }
  double ans = ((double)num/(double)count);
  cout << fixed;
  cout << setprecision(2);
  cout << ans << endl;
  return 0;
}
