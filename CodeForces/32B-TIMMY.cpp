#include <iostream>
#include <cstring>

using namespace std;

#define MAX 212

int main(void){
  char str[MAX];
  int len;
  cin >> str;
  len = strlen(str);
  for(int i = 0; i < len; i++){
    if(str[i] == '.') cout << 0;
    else{
      cout << (str[i+1] == '.' ? 1 : 2);
      i++;
    }
  }
  cout << '\n';
  return 0;
}
