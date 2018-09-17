#include <bits/stdc++.h>

#define DEBUG 0
#define debugf if(DEBUG) printf

typedef long long ll;

const int MAX = 1123456;

int n, e, c, p, q, toti, d;
int PI[MAX], pi;

ll expbin(ll a, ll b, ll m){
  ll y;
  if(b == 0) return 1;
  if(b & 1) return a * expbin(a, b-1, m) % m;
  y = expbin(a, b >> 1, m);
  return (y * y) % m;
}

void crivo(int n) {
  int i, j, raiz, primo;
  PI[0] = 2; pi = 1;
  for(i = 3; i <= n; i++){
    primo = 1; raiz = sqrt(i);
    for(j = 0; primo && j < pi && PI[j] <= raiz; j++)
      if(i % PI[j] == 0) primo = 0;
    if(primo) PI[pi++] = i;
  }
}

ll extGcd(ll a, ll b, ll &x, ll &y){
  if(b == 0) {x = 1; y = 0; return a;}
  else{
    ll g = extGcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
  }
}

ll modInv(ll a, ll m){
  ll x, y;
  extGcd(a, m, x, y);
  return(x % m + m) % m;
}

int main(void){
  scanf("%d %d %d", &n, &e, &c);
  crivo(sqrt(n)+1);
  for(int i = 0; i < pi; i++)
    if(n % PI[i] == 0) {p = PI[i]; break;}
  q = n/p;
  debugf("%d %d\n", p, q);
  toti = (q-1)*(p-1);
  d = modInv(e, toti);
  debugf("%d\n", d);
  printf("%lld\n", expbin(c, d, n)); 
  
  return 0;
}
