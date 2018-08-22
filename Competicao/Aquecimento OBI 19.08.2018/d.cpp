#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

int main(void){
  ios::sync_with_stdio(false);
  int n, m;
  int line[MAXV], col[MAXV];
  int mdist = 0;
  cin >> n >> m;
  for(int i = 0;i < n; i++){
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      //cout << c;
      if(c == '@'){
	//cout << i << " " << j << "\n";
	line[i] = col[j] = 1;
	int mi = max(i, n-i);
	int mj = max(j, m-j);
	mdist = max(mdist, max(mi, mj));
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(line[i] == 1) continue;
    for(int j = 0; j< n; j++){
      if(col[j] == 0){ cout << -1 << " " << i << " " << j << "\n"; return 0; }
    }
  }
  cout << mdist << "\n";
  return 0;
}
