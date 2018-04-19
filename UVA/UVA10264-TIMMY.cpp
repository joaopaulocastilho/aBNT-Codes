#include <cstdio>
#include <cstring>

#define MAX 112345

int main(void){
  int v[MAX], pot[MAX], sz, sum, ans, maxc, j, num, i;
  while(scanf("%d", &sz) != EOF ){
    memset(pot, 0, sizeof(pot));
    memset(v, 0, sizeof(v));
    for(i = 0, maxc = 1; i < sz; i++) maxc *= 2;;
    for(i = 0; i < maxc; i++)
      scanf("%d", &v[i]);
    for(i = 0; i < maxc; i++){
      for(j = 0, num = 1; j < sz; j++, num = (num << 1)){
	pot[i] += v[(i ^ num)];
      }
    }
    ans = -1;
    for(i = 0; i < maxc; i++){
      for(j = 0, num = 1; j < sz; j++, num = (num << 1)){
	sum = pot[i] + pot[i^num];
	if(ans < sum) ans = sum;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
