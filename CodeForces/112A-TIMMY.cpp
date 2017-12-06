#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void){
  string str1, str2;
  cin >> str1;
  cin >> str2;
  for(int i = 0; i < (int) str1.length(); i++){
    str1[i] = str1[i] > 90 ? str1[i] - 97 : str1[i] - 65;
    str2[i] = str2[i] > 90 ? str2[i] - 97 : str2[i] - 65;
    if(str1[i] == str2[i]) continue;
    if(str1[i] < str2[i]){ printf("-1\n"); return 0; }
    printf("1\n");
    return 0;
  }
  printf("0\n");
  return 0;
}
