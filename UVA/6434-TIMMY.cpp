#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int v[MAXV], n, m, memo[MAXV][MAXV][MAXV];

int pd(int i, int qtd, int bigger){
  if(memo[i][qtd][bigger] != -1) return memo[i][qtd][bigger];
  if(i == 0){ return v[bigger] - v[0]; }
  if(qtd == 1) return memo[i][qtd][bigger] = pd(i-1, qtd, bigger);
  return memo[i][qtd][bigger] = min(pd(i-1, qtd, bigger), pd(i-1, qtd-1, i-1) + v[bigger] - v[i]);
}

int main(void){
  int t; cin >> t;
  for(int caso = 1; caso <= t; caso++){
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    sort(v, v+n);
    cout << "Case #" << caso << ": ";
    if(m == 1) cout << v[n-1] - v[0];
    else cout << pd(n-1, m, n-1);
    cout << endl;
  }


  return 0;
}
