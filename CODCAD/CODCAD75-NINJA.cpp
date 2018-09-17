#include <bits/stdc++.h>

const int MAX = 1123;

typedef long long ll;

int n, m, k, a[MAX];
ll f[MAX];

ll dp(int k){
  int i, ans;

  if(f[k] != -1) return f[k];
  for(ans = 0, i = 1; i <= n; i++) ans = (ans + (a[i] * dp(k-i)) % m) % m;
  return f[k] = ans;
}

int main(void){
  int i;

  memset(f, -1, sizeof(f));
  scanf("%d %d %d", &n, &k, &m);
  for(i = 1; i <= n; i++) scanf("%d", &a[i]);
  for(i = 1; i <= n; i++) scanf("%lld", &f[i]);

  printf("%lld\n", dp(k));
  
  return 0;
}
