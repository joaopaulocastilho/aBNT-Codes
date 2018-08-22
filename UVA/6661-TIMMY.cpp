#include <bits/stdc++.h>

using namespace std;

const int MAXS = 212;
const int MAXK = 20;
const int MAXN = 30;

int n, k, s;
int memo[MAXK][MAXS][MAXN];

int pd(int t, int soma, int num){
  if(t == 0){
    if(soma != 0) return 0;
    else return 1;
  }
  if(memo[t][soma][num] != -1) return memo[t][soma][num];
  memo[t][soma][num] = 0;
  for(int i = num; i <= n; i++){
    //cout << t << " " << soma-i << endl;
    if(soma - i >= 0) memo[t][soma][num] += pd(t-1, soma-i, i+1);
  }
  return memo[t][soma][num];
}

int main(void){
  int ans;
  while(cin >> n >> k >> s, n){
    memset(memo, -1, sizeof(memo));
    ans = pd(k, s, 1);
    cout << ans << "\n";
  }

  return 0;
}
