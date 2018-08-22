#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000000;
const int MAXV = 112345;

int n, f;
int v[MAXV];

int solve(int num){
  int ans = 0;
  for(int i = 0;i < n; i++){
    ans += num/v[i];
  }
  return (ans >= f);
}

int bbin(int menor, int maior){
  int ans;
  int med;
  while(maior > menor){
    med = (menor+maior)/2;
    //cout << maior << " " << menor << "\n";
    if(solve(med)){
      maior = med-1;
      ans = med;
    }
    else menor = med+1;
  }
  med = (maior+menor)/2;
  if(solve(med)) ans = med;
  return ans;
}

int main(void){
  cin >> n >> f;
  
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  cout << bbin(1, MAX) << endl;
  return 0;
}
