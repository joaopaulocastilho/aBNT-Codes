#include <bits/stdc++.h>

using namespace std;

const int MAXV = 11;

int main(void){
  int n;
  double sum = 0;
  cin >> n;
  int maior = -1, smaior = -1;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    sum += num;
    if(num > maior){ smaior = maior; maior = num; }
    else if(num > smaior){ smaior = num; }
  }
  if(maior >= (sum*0.45) || ((maior >= sum*0.40) && (maior - smaior) >= sum*0.1))
    cout << "1\n";
  else cout << "2\n";
  return 0;
}
