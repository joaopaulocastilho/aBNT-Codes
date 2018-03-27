#include <stdio.h>
#include <math.h>

#define MAX 31

typedef long long ll;

int main(void){
  int tmp, t, i, d, k, term, nterms, pol[MAX];
  ll ans;

  scanf("%d", &t);
  while(t--){
    scanf("%d", &nterms);
    for(ans = i = 0; i < nterms+1; i++) scanf("%d", &pol[i]);
    scanf("%d %d", &d, &k);
    for(tmp = 0, term = 1; ;term++){
      tmp += d * term;
      if(tmp >= k) break;
    }
    //printf("%d\n", term);
    for(i = 0; i < nterms+1; i++){
      ans += pol[i]  * pow(term, i);
      //printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
  }
}
