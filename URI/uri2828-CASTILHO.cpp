#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXV = 112345;
const int P = 1000000007;

int fr[MAXV];
ll vfat[MAXV];
char s[MAXV];

void fat(int n) {
  int i;
  vfat[0] = 1;
  for (i = 1; i < n; i++) vfat[i] = (vfat[i - 1] * i) % P;
}

ll expbin(ll a, ll b, ll m) {
  ll y;
  if (b == 0) return 1;
  if (b & 1) return a * expbin(a, b - 1, m) % m;
  y = expbin(a, b >> 1, m);
  return (y * y) % m;
}

int main(void) {
  int n, i;
  ll num, den;
  scanf("%s", s);
  fat(MAXV);
  n = strlen(s); num = vfat[n];
  for (i = 0; i < n; i++) fr[s[i] - 'a']++;
  for (den = 1, i = 0; i <= 'z' - 'a'; i++)
    den = (den * vfat[fr[i]]) % P;
  printf("%lld\n", (num * expbin(den, P - 2, P)) % P);
  return 0;
}
