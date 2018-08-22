#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
  vector<pair<int, int> > vp;
  pair<int, int> anterior;
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int dist, cor;
    cin >> dist;
    cin >> cor;
    vp.push_back(make_pair(dist, cor));
  }
  sort(vp.begin(), vp.end());
  int r = 1;
  for(int i = 0; i < n; i++){
    if(i != 0){
      if(anterior.second < vp[i].second) r = 0;
    }
    anterior = vp[i];
  }
  if(r == 1) cout << "S\n";
  else cout << "N\n";
  return 0;
}
