#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

int n, m;

int main(void){
  cin >> n >> m;
  long long int dif[MAXV];
  long long int sum = 0;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    sum += a;
    dif[i] = a-b;
  }
  if(sum <= m){ cout << "0\n"; return 0; }
  sort(dif, dif+n);
  int end = 0, count = 0, j;
  for(j = n-1; j >= 0; j--){
    sum -= dif[j];
    count++;
    if(sum <= m){ end = 1; break; }
  }
  if(end == 0) cout << "-1\n";
  else cout << count << "\n";
  return 0;
}
