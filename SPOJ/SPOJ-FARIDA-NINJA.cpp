#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 11234;

int n,  mon[MAX];
ll memo[MAX];

ll dp(int i){
  if(memo[i] != -1) return memo[i];
  if(i >= n) return 0;
  return memo[i] = max(dp(i+2) + mon[i], dp(i+1));
}

int main(void){
  int i, t, caso = 1;

  scanf("%d", &t);
  while(t--){
    memset(memo, -1, sizeof(memo));
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &mon[i]);
    printf("Case %d: %lld\n", caso++,  dp(0));
  }

  return 0;
}
