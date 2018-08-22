#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int v[MAXV];

int main(void){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int l, r;
    cin >> l >> r;
    for(int j = l; j <= r; j++){
      v[j] = 1;
    }
  }
  vector<int> vi;
  int count = 0;
  for(int i = 1; i <= m; i++){
    if(v[i] == 0){ count++; vi.push_back(i); }
  }
  cout << count << "\n";
  for(int i = 0; i < (int)vi.size(); i++){
    cout << (i == 0 ? "" : " ") << vi[i];
    if(i == (int)vi.size()-1)   cout << "\n";
  }
  return 0;
}
