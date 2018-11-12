#include <bits/stdc++.h>

using namespace std;

int main(void){
  vector<int> v, aux;
  for(int i = 0; i < 5; i++){
    int num;
    cin >> num;
    v.push_back(num);
  }
  aux = v;
  sort(v.begin(), v.end(), greater<int>());
  int gr = 1;
  for(int i = 0;i < 5; i++){
    if(v[i] != aux[i]) gr = 0;
  }
  int ls = 1;
  sort(v.begin(), v.end(), less<int>());
  for(int i = 0;i < 5; i++){
    if(v[i] != aux[i]) ls = 0;
  }
  if(ls == 0 && gr == 0) cout << "N\n";
  else if(ls == 0) cout << "D\n";
  else cout << "C\n";
  return 0;
}
