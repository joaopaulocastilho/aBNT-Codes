#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXV = 112;

int main(void){
  int v[MAXV];
  int tc; cin >> tc;
  int maior, idx, flag[MAXV], idxs[MAXV];
  for(int caso = 1; caso <= tc; caso++){
    cout << "Case #" << caso << ": ";
    memset(flag, 0, sizeof(flag));
    memset(idxs, 0, sizeof(idxs));
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    if(n == m){ cout << "0" << endl; continue; }
    sort(v, v+n);
    if(m == 1){ cout << v[n-1] - v[0] << endl; continue; }
    for(int i = 0; i < m-1; i++){
      maior = -1;
      for(int j = 0; j < n-1; j++){
	if(maior < v[j+1] - v[j] && !flag[j]){
	  //cout << maior << " " << v[j+1] - v[j] << endl;
	  maior = v[j+1] - v[j]; idx = j;
	}
      }
      //cout << maior << endl;
      flag[idx] = 1;
      idxs[i] = idx;
    }
    sort(idxs, idxs+m-1);
    /*cout << "TO NO SORT" << endl;
    for(int i = 0; i < m-1; i++){
      cout << idxs[i] << " ";
    }
    cout << endl;
    */
    int tmp = 0;
    tmp += v[idxs[0]] - v[0];
    for(int i = v[idxs[0]+1], j = 1; j < m-1; j++){ 
      int aux = v[idxs[j]];
      tmp += aux - i;
      if(j != m-2){ i = aux+1; aux = v[idxs[j+1]]; }
    }
    tmp += v[n-1] - v[idxs[m-2]+1];
    cout << tmp << endl;
  }
  
  return 0;
}
