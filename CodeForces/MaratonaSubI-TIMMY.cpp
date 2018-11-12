#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

int main(void){
  int n, m, qtd, num, v[MAXV], conf[MAXV], ans;
  cin >> n >> m;
  vector<vector<int> > switches;
  cin >> qtd;
  for(int i = 0; i < qtd; i++){
    cin >> num;
    v[--num] = 1;
  }
  
  for(int i = 0; i < m; i++){
    conf[i] = v[i];
  }
  for(int i = 0; i < n; i++){
    vector<int> swit;
    cin >> qtd;
    for(int j = 0; j < qtd; j++){
      cin >> num;
      swit.push_back(--num);
    }
    switches.push_back(swit);
  }
  /*
    for(int i = 0; i < (int)switches.size(); i++){
    cout << i << ": ";
    for(int j = 0; j < (int)switches[i].size(); j++){
    cout << switches[i][j] << " ";
    }
    cout << "\n";
    }
  */
  int done = 0, count = 1;
  while(!done){
    for(int i = 0; i < (int)switches.size() && !done; i++){
      for(int j = 0; j < (int)switches[i].size(); j++){
	v[switches[i][j]] = !v[switches[i][j]];
      }
      int term = 1;
      for(int j = 0; j < m; j++){
	if(v[j] == 1){ term = 0; break; }
      }
      if(term){ ans = count; done = 1; break; }
      count++;
    }
    //for(int i = 0; i < m; i++){
      //cout << v[i] << " ";
      //}
    //cout << "\n";
    int igual = 1;
    for(int j = 0; j < m; j++)
      if(v[j] != conf[j]){ igual = 0; break; }
    if(igual && !done){ ans = -1; done = 1; }
  }
  cout << ans << "\n";
  return 0;
}
