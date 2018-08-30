#include <bits/stdc++.h>

#define DEBUG false
#define debugf if(DEBUG) printf

typedef long long ll;

using namespace std;

const int MAXV = 12345;

int n, e, c;
int PI[MAXV], pi;
int pprimo, sprimo;

void crivo(int n){
  int i, j, primo, raiz;
  PI[0] = 2; pi = 1;
  for(i = 3; i <= n; i++){
    primo = 1; raiz = sqrt(i);
    for(j = 0; j < pi && PI[j] <= raiz && primo; j++)
      if(i % PI[j] == 0) primo = 0;
    if(primo) PI[pi++] = i;
  }
}

void fatora(int n){
  int para = 0;
  for(int i = 0; i < pi && !para; i++){
    if(n % PI[i] == 0){
      pprimo = PI[i];
      sprimo = n/PI[i];
      para = 1;
    }
  }
}

ll expbin(ll a, ll b, ll m){
  ll y;
  if(b == 0) return 1;
  if(b & 1) return a * expbin(a, b-1, m) %m;
  y = expbin(a, b >> 1, m);
  return (y*y)%m;

}

ll extGcd(ll a, ll b, ll &x, ll &y){
  if(b == 0){
    x = 1; y = 0; return a;
  }
  else{
    ll g = extGcd(b, a%b, y, x);
    y -= a/b * x;
    return g;
  }
}

ll modInv(ll a, ll m){
  ll x, y;
  extGcd(a, m, x, y);
  return (x%m + m) %m;
}

int main(void){
  ll x, y;
  ios::sync_with_stdio(false);
  ll tot;
  ll d, m;
  cin >> n >> e >> c;
  crivo(sqrt(n));
  fatora(n);
  //cout << pprimo << " " << sprimo << "\n";
  tot = (pprimo-1)*(sprimo-1);
  d = modInv(e, tot);
  //cout << d << "\n";
  m = expbin(c, d, n);
  cout << m << "\n";
  return 0;
}
