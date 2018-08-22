#include <bits/stdc++.h>

using namespace std;

int main(void){
  int num;
  int k, l;
  for(int i = 1; i <= 16; i++){
    cin >> num;
    if(num == 1) k = i;
    if(num == 9) l = i;
  }
  if((k <= 8 && l > 8) || (l <= 8 && k > 8))
    cout << "final\n";
  else if((k <= 4 && l > 4) || (k <= 12 && l > 12) || (l <= 4 && k > 4) || (l <= 12 && k > 12))
    cout << "semifinal\n";
  else if((k <= 2 && l > 2) || (k <= 6 && l > 6) || (k <=10 && l > 10) || (k <= 14 && l > 14) ||
	  (l <= 2 && k > 2) || (l <= 6 && k > 6) || (l <=10 && k > 10) || (l <= 14 && k > 14))
    cout << "quartas\n";
  else cout << "oitavas\n";
  return 0;
}
