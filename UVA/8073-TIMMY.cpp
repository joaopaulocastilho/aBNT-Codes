#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;
const int MAXM = 21234;

int n, m;
int v[MAXV];
int memo[MAXV][MAXM];

int pd(int i, int qtd){
  int med = (qtd*2)/3;
  if(i >= n) return 0;
  if(memo[i][qtd] != -1) return memo[i][qtd];
  int eat = qtd > v[i] ? v[i] : qtd;
  memo[i][qtd] = max(pd(i+1, med)+eat, max(pd(i+2, qtd)+eat, pd(i+3, m)+eat));
  return memo[i][qtd];
}

int main(void){
  int ans;
  while(cin >> n >> m){
    ans = -1;
    for(int i = 0; i < n; i++) cin >> v[i];
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++){
      ans = max(ans, pd(i, m));
    }
    cout << ans << "\n";
  }
  return 0;
}
