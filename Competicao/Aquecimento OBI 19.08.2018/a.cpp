#include <bits/stdc++.h>

using namespace std;

int main(void){
  string str;
  while(getline(cin, str)){
    if(str == "esquerda") cout << "ingles";
    if(str == "direita") cout << "frances";
    if(str == "nenhuma") cout << "portugues";
    if(str == "as duas") cout << "caiu";
    cout << "\n";
  }
  return 0;
}
