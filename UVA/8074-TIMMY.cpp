#include <bits/stdc++.h>

using namespace std;

const int MAXI = 100;
const int MAXJ = 100;

int movi[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int movj[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int movs = 8;
int matrix[MAXI][MAXJ];
int n, m;

int valido(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int idxi, int idxj, int num){
  //cout << idxi << " " << idxj << "\n";
  matrix[idxi][idxj] = num;
  for(int i = 0; i <= movs; i++){
    if(valido(idxi+movi[i], idxj+movj[i]) && matrix[idxi+movi[i]][idxj+movj[i]] == 0) dfs(idxi+movi[i], idxj+movj[i], num);
  }
}

int main(void){
  while(cin >> n >> m){
    //cout << n << " " << m << "\n";
    memset(matrix, -1, sizeof(matrix));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        char num;
        cin >> num;
        matrix[i][j] = (num == '.' ? -1 : 0);
      }
    }

    int count = 1;
    for(int i = 0; i < n; i++){
      for(int j = 0; j< m; j++){
        if(matrix[i][j] == 0){ dfs(i, j, count); count++; }
      }
    }
    cout << count-1 << "\n";
  }


  return 0;
}
