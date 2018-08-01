#include <stdio.h>

#define next(i) (i == n-1 ? 0 : i + 1)
#define prev(i) (i == 0 ? n-1 : i - 1)

int const MAX = 11234;

int main(void){
  int n, v[MAX], i, ans;

  while(scanf("%d", &n), n){
    for(i = 0; i < n; i++) scanf("%d", &v[i]);
    for(ans = i = 0; i < n; i++)
      if((v[prev(i)] > v[i] && v[next(i)] > v[i]) ||
	 (v[prev(i)] < v[i] && v[next(i)] < v[i])) ans++; 
    printf("%d\n", ans);
  }
  return 0;
}
