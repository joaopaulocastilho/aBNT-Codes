#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

int v[MAXV][MAXV], aux[MAXV][MAXV];
int movi[] = { 0, 1, -1, 0};
int movj[] = { 1, 0, 0, -1};
int n, m;

int valido(int i, int j){
  return (i >= 0 && j >= 0 && i < n && j < n);
}

int solve(int step){
  memset(aux, 0, sizeof(aux));
  for(int i = 0; i < n; i++){
    for(int j = 0;j < m; j++){
      if(v[i][j] == 1){
        aux[i][j] = -1;
        int found[4];
        memset(found, 0, sizeof(found));
        for(int k = 1; k < step; k++){
          for(int l = 0; l < 4; l++){
            if(!valido(i+movi[l]*k, j+movj[l]*k)) continue;
            if(v[i+movi[l]*k][j+movj[l]*k] == 1){ found[l] = 1; continue; }
            if(!found[l]){
              v[i+movi[l]*k][j+movj[l]*k] = -1;
            }
          }
        }
      }
    }
  }

  int flag = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0;j < m; j++){
      if(aux[i][j] == 0) flag = 0;
    }
  }
  return flag;
}

int bbin(int l, int r){
  int ans, med;
  while(l < r){
    cout << l << " " << r << "\n";
    med = (l+r)/2;
    if(solve(med)){
      l = med+1;
      ans = med;
    }
    else r = med-1;
  }
  med = (l+r)/2;
  if(solve(med)) ans = med;
  return ans;
}

int main(void){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j= 0; j < m; j++){
      char c;
      cin >> c;
      v[i][j] = (c == '#' ? 0 : 1);
    }
  }

  int ans = bbin(1, 1000);
  cout << ans << endl;
  return 0;
}
