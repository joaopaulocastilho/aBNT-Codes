#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int matrix[][7]={
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 1, 0, 1, 1 }  // 9
};

vector<string> pos;

int bt(int i, int idx, int bad[]){
  int ans = 0;
  if((int)pos.size() == idx) return 1;
  if(i == -1) return 0;
  int j;
  for(j = 0; j < 7; j++){
    if(bad[j] == 1 && pos[idx][j] == 'Y') break;
    if(pos[idx][j] == 'Y' && matrix[i][j] != 1) break;
    if(pos[idx][j] == 'N' && matrix[i][j] == 1) bad[j] = 1;
  }
  if(j == 7) ans |= bt(i-1, idx + 1, bad);
  return ans;
}

int main(void){
  int tc;
  string padrao;
  while(cin >> tc, tc){
    int ans = 0;
    pos.clear();
    for(int l = 0; l < tc; l++){
      cin >> padrao;
      pos.push_back(padrao);
    } 
    int i, j;
    int bad[10];
    for(i = 0; i < 10; i++){
      memset(bad, 0, sizeof(bad));
      for(j = 0; j < 7; j++){
	if(pos[0][j] == 'Y' && matrix[i][j] != 1) break;
	if(pos[0][j] == 'N' && matrix[i][j] == 1) bad[j] = 1;
      }
      if(j == 7) ans |= bt(i-1, 1, bad);
    }
    cout << ((ans == 1) ? "MATCH" : "MISMATCH") << "\n";
  }
  return 0;
}
