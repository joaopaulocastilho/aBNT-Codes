#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;
const int INF = 1123456789;
int main(void){
  ios::sync_with_stdio(false);
  vector<vector<int> > vi(112);
  int v[MAXV];
  int n;
  cin >> n;
  for(int i = 0;i < n; i++){
    cin >> v[i];
    vi[v[i]].push_back(i);
  }
  /*
  for(vector<vector<int> >::iterator it = vi.begin(); it <= vi.end() && (int)(*it).size() > 0; ++it){
    sort((*it).begin(), (*it).end());
  }
  */
  for(int i = 0; i < n; i++){
    int menor = INF;
    for(int j = v[i]+1; j <= 100; j++){
      int found = 0, k;
      for(k = 0; k < (int)vi[j].size() && found == 0; k++){
	if(vi[j][k] > i){
	  found = 1;
	  if(vi[j][k] < menor) menor = vi[j][k];
	}
      }
    };
    cout << (i == 0 ? "" : " ");
    if(menor == INF) cout << "*";
    else cout << v[menor];
  }
  cout << endl;
  return 0;
}
