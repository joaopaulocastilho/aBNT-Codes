#include <bits/stdc++.h>

using namespace std;

int n;

int pd(int i, int r){
  int num = 1, pot = 1;
  int soma;
  
  if(str[i] != ?) return memo[i][r] = str[i]-'0';
  
  for(int j = 0; j < 10; j++){
    for(int k = 0; k < i; k++){
      num = (num * pot) % n;
      pot = 10;
    }

    soma = (num + r)%n;
    
  }
}

int main(void){
  string str;
  cin >> str >> n;
  len = str.size();
  pd(len, 0);

  return 0;
}
