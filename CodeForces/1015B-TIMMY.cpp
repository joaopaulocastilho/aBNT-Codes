#include <bits/stdc++.h>

using namespace std;

const int MAXV = 30;

int main(void){
  int n; cin >> n;
  string s, t;
  int v[MAXV];
  vector<int> ansv;
  memset(v, 0, sizeof(v));
  cin >> s >> t;
  for(int i = 0; i < (int)s.size(); i++){
    v[(s[i]-'a')]++;
  }
  for(int i = 0; i < (int)s.size(); i++){
    v[(t[i]-'a')]--;
  }
  for(int i = 0; i < 27; i++){
    if(v[i] != 0){ cout << "-1\n"; return 0; }
  }
  int id = 0, count = 0;
  while(s != t){
    for(int i = id; i < (int)s.size(); i++){
      if(s[i] == t[id] && i == id){ id++; continue; }
      if(s[i] == t[id] && i != id){
	//cout << i << " -> " << id << '\n';
	for(int j = i-1; j >= id; j--){
	  ansv.push_back(j+1);
	  count++;
	  swap(s[j], s[j+1]);
	}
	id++;
      }
    }
  }
  cout << count << "\n";
  for(int i = 0; i < (int)ansv.size(); i++){
    cout << (i == 0 ? "" : " ") << ansv[i];
    cout << (i == ((int)ansv.size()-1) ? "\n" : "");
  }
  return 0;
}
