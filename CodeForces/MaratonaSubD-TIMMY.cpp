#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, count = 0;
  cin >> n;
  while(n--){
    int num;
    cin >> num;
    if(num != 1) count++;
  }
  cout << count << "\n";
  return 0;
}
