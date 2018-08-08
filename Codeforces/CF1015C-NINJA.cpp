#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
  int i, n, m, ans, size, comp;
  vector<ll> dif;
  ll ttl = 0;
  
  scanf("%d %d", &n, &m);
  while(n--){
    scanf("%d %d", &size, &comp);
    dif.push_back(size-comp);
    ttl += size;
  }
  sort(dif.begin(), dif.end());
  for(ans = 0, i = dif.size()-1; i >= 0 && ttl > m; ttl -= dif[i], i--, ans++);
  printf("%d\n", ttl <= m ? ans : -1);
  
  return 0;
}
