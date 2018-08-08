#include <bits/stdc++.h>

#define EPS 10e-9

using namespace std;

int main(void){
  int ttl, i, num, n;
  vector<int> v;
  
  scanf("%d", &n);
  for(ttl = i = 0; i < n; i++){
    scanf("%d", &num);
    v.push_back(num);
    ttl += num;
  }
  sort(v.begin(), v.end());
  if(0.45 * ttl - v[n-1] <= EPS) printf("1\n");
  else if(0.4 * ttl - v[n-1] <= EPS && v[n-1] - v[n-2] - 0.1 * ttl >= -EPS) printf("1\n");
  else printf("2\n");

  return 0;
}
