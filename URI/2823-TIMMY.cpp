#include <bits/stdc++.h>

#define EPS 10e-9

using namespace std;

int main(void){
  int n;
  cin >> n;
  double ans = 0;
  for(int i = 0; i < n; i++){
    double c, p;
    cin >> c >> p;
    ans += c/p;
  }
  cout << (ans - 1 < EPS ? "OK\n" : "FAIL\n");
  return 0;
}
