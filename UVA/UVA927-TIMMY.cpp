#include <cstdio>

#define MAX 24

unsigned long long int pau(int n, int l){
  unsigned long long int ans = 1;
  if(l == 0) return 1;
  if(l == 1) return n;
  for(int i = 0; i < l; i++){
    ans *= n;
  }
  return ans;
}

int main(void){
  unsigned long long int ans;
  int tc, i, j, v[MAX], n, l, count, d, k, tmp;
  scanf("%d", &tc);
  while(tc--){
    ans = 0;
    n = 0;
    count = 0;
    tmp = 0;
    scanf("%d", &i);
    for(j = 0; j <= i; j++){
      scanf("%d", &v[j]);
    }
    scanf("%d %d", &d, &k);
    while(count < k){
      tmp++;
      count += tmp * d;
    }
    for(l = 0; l <= i; l++){
      ans += v[l] * pau(tmp, l);
    }
    for(l = 0; l < (d*n); l++){
      count++;
    }
    printf("%llu\n", ans);
  }
  return 0;
}
