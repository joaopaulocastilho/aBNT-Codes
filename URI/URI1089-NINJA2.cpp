#include <stdio.h>

int const MAX = 11234;

int main(void){
  int n, v[MAX], i, ans;

  while(scanf("%d", &n), n){
    for(i = 0; i < n; i++) scanf("%d", &v[i]);
    for(ans = i = 0; i < n; i++)
      if((v[(i-1+n)%n] > v[i] && v[(i+1)%n] > v[i]) ||
	 (v[(i-1+n)%n] < v[i] && v[(i+1)%n] < v[i])) ans++; 
    printf("%d\n", ans);
  }
  return 0;
}
