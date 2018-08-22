#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

int movi[] = {1, 0, -1, 0};
int movj[] = {0, 1, 0, -1};
int n, m;
int mx[MAXV][MAXV];
int got[MAXV][MAXV];


typedef struct{
  int x, y;
} ans_t;

int valido(int i, int j){
  return i >= 0 && j >= 0 && i < n && j < m;
}

int main(void){
  map<pair<int, int>, int> mp;
  memset(got, 0, sizeof(got));
  vector<ans_t> ans;
  ans.clear();
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c; cin >> c;
      mx[i][j] = c == '.' ? 0 : 1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(mx[i][j] == 1){
	int size = 1;
	int ok = 1;
	ans_t aux;
	while(ok){
	  for(int k = 0; k < 4; k++){
	    if(!valido(i + movi[k]*size, j + movj[k]*size)){
	      ok = 0;
	    }
	    else if(mx[i + movi[k]*size][j + movj[k]*size] != 1){ ok = 0; }
	  }
	  //cout << i << " " << j << " " << size << " " << ok << "\n";
	  if(ok){
	    got[i][j] = 1;
	    for(int k = 0; k < 4; k++)
	      got[i + movi[k]*size][j + movj[k]*size] = 1;
	    mp[make_pair(i,j)] = (mp[make_pair(i,j)] < size ? size : mp[make_pair(i,j)]);
	    aux.x = i; aux.y = j;
	    ans.push_back(aux);
	    size++;
	  }
	}
      }
    }
  }
  int flag = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      //cout << got[i][j] << " ";
      if(got[i][j] == 0 && mx[i][j] == 1) flag = -1;
    }
    //cout << "\n";
  }
  if(flag != -1){
    int count = 0;
    for(int i = 0; i < (int)ans.size(); i++){
      if(i == 0 || ans[i].x != ans[i-1].x || ans[i].y != ans[i-1].y) count++;
    }
    cout << count << "\n";
    for(int i = 0; i < (int)ans.size(); i++){
      if(i < 0)
	cout << ans[i].x+1 << " " << ans[i].y+1 << " " << mp[make_pair(ans[i].x,ans[i].y)] << "\n";
      else if(ans[i].x != ans[i-1].x || ans[i].y != ans[i-1].y)
	cout << ans[i].x+1 << " " << ans[i].y+1 << " " << mp[make_pair(ans[i].x,ans[i].y)] << "\n";
    }
  }
  else cout << "-1\n";
  return 0;
}
