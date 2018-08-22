#include <bits/stdc++.h>

const int MAXV = 112345;
const int INF = 112345678;
using namespace std;

int ov[MAXV];
int n;

int merge_sort(vector<int> &v){
  int inv = 0;
  if(v.size() == 1) return 0;
  int ini1=0, ini2=0;
  vector<int> u1, u2;
  for(int i = 0;i < (int)v.size()/2; i++){
    u1.push_back(v[i]);
  }
  for(int i = v.size()/2; i < (int)v.size(); i++){
    u2.push_back(v[i]);
  }  
  inv += merge_sort(u1);
  inv += merge_sort(u2);
  u1.push_back(INF);
  u2.push_back(INF);
  for(int i = 0;i < (int)v.size(); i++){
    if(u1[ini1] <= u2[ini2]){
      v[i] = u1[ini1];
      ini1++;
    }
    else{
      v[i] = u2[ini2];
      ini2++;
      inv+= u1.size()-ini1-1;
    }
  }  
  return inv;
}

int main(void){
  int ans;
  vector<int> v;
  while(cin >> n, n){
    v.clear();
    for(int i = 0; i < n; i++){
      int num; cin >> num;
      v.push_back(num);
    }
    ans = merge_sort(v);
    //for(int i = 0; i < n; i++) cout << v[i];
    cout << (ans%2 == 0 ? "Carlos" : "Marcelo") << "\n";
  }
  return 0;
}
